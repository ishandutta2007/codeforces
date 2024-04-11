#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <ios>

using namespace std;

typedef long long ll;

const int maxn = 1<<18;
const int mod = 1e9 + 7;

int v[maxn], q, qt[maxn], qv[maxn];
int ent[maxn], exi[maxn], cnt;
vector<int> adj[maxn];

void dfs(int cur) {
    ent[cur] = cnt++;
    for (int i : adj[cur])
        dfs(i);
    exi[cur] = cnt++;
}

int tree[4 * maxn], lazy[4 * maxn], mul[4 * maxn];

void mult(int& a, int b) {
    a = ll(a) * b % mod;
}

void push(int cur, int lt, int rt) {
    mult(tree[cur], lazy[cur]);
    mult(mul[cur], lazy[cur]);
    if (lt + 1 != rt) {
        mult(lazy[2 * cur], lazy[cur]);
        mult(lazy[2 * cur + 1], lazy[cur]);
    }
    lazy[cur] = 1;
}

void upd(int cur, int lt, int rt, int ql, int qr, int k) {
    push(cur, lt, rt);
    if (rt <= ql || lt >= qr) return;
    else if (lt >= ql && rt <= qr) {
        lazy[cur] = k;
        push(cur, lt, rt);
    } else {
        int mid = (lt + rt) / 2;
        upd(2 * cur, lt, mid, ql, qr, k);
        upd(2 * cur + 1, mid, rt, ql, qr, k);
        tree[cur] = (tree[2 * cur] + tree[2 * cur + 1]) % mod;
    }
}

void add(int cur, int lt, int rt, int p, int k) {
    if (lt + 1 == rt) {
        tree[cur] = ll(k) * mul[cur] % mod;
    } else {
        int mid = (lt + rt) / 2;
        push(2 * cur, lt, mid);
        push(2 * cur + 1, mid, rt);
        if (p < mid) add(2 * cur, lt, mid, p, k);
        else add(2 * cur + 1, mid, rt, p, k);
        tree[cur] = (tree[2 * cur] + tree[2 * cur + 1]) % mod;
    }
}

int getm(int cur, int lt, int rt, int p) {
    if (lt + 1 == rt) return mul[cur];
    else {
        int mid = (lt + rt) / 2;
        push(2 * cur, lt, mid);
        push(2 * cur + 1, mid, rt);
        if (p < mid) return getm(2 * cur, lt, mid, p);
        else return getm(2 * cur + 1, mid, rt, p);
    }
}

int qry(int cur, int lt, int rt, int ql, int qr) {
    push(cur, lt, rt);
    if (rt <= ql || lt >= qr) return 0;
    else if (lt >= ql && rt <= qr) return tree[cur];
    else {
        int mid = (lt + rt) / 2;
        return (qry(2 * cur, lt, mid, ql, qr) + qry(2 * cur + 1, mid, rt, ql, qr)) % mod;
    }
}

int exp(int b, int e) {
    if (!e) return 1;
    if (e & 1) return ll(exp(b, e - 1)) * b % mod;
    int x = exp(b, e >> 1);
    return ll(x) * x % mod;
}

int n;
int s[maxn];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> v[0] >> q;
    n = 1;
    for (int i = 0; i < q; i++) {
        cin >> qt[i];
        if (qt[i] == 1) {
            cin >> qv[i] >> v[n];
            qv[i]--;
            adj[qv[i]].push_back(n);
            n++;
        } else {
            cin >> qv[i];
            qv[i]--;
        }
    }

    dfs(0);

    for (int i = 0; i < 4 * maxn; i++) lazy[i] = mul[i] = 1;

    add(1, 0, 2 * n, ent[0], v[0]);
    s[0] = 1;
    for (int i = 0, c = 1; i < q; i++) {
        if (qt[i] == 1) {
            int x = qv[i];
            upd(1, 0, 2 * n, ent[x], exi[x], ll(s[x] + 1) * exp(s[x], mod - 2) % mod);
            add(1, 0, 2 * n, ent[c], v[c]);
            s[x]++, s[c]++, c++;
        } else {
            int x = qv[i];
            int res = qry(1, 0, 2 * n, ent[x], exi[x]);
            int k = getm(1, 0, 2 * n, ent[x]);
            cout << ll(res) * exp(k, mod - 2) % mod * s[x] % mod << '\n';
        }
    }
}