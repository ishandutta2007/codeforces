#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

typedef long long ll;

const int MAXN = 1<<17;
const int MAXLG = 20;

int n, m, a[MAXN];
bool b[MAXLG][MAXN];

struct data {
    ll sum, lt, num; //current sum, leftmost 0, number right
    data() {}
    data(ll _sum, ll _lt, ll _num) : sum(_sum), lt(_lt), num(_num) {}
} tree[MAXLG][2*MAXN];

data prop(data d1, data d2, int lt, int mid, int rt) {
    return data(d1.sum + d2.sum + d1.num * (d2.lt - mid),
                d1.lt == mid ? d2.lt : d1.lt,
                d2.lt == rt ? d1.num + d2.num : d2.num);
}

void init(int c, int cur, int lt, int rt) {
    if (lt + 1 == rt) tree[c][cur] = data(b[c][lt], lt + b[c][lt], b[c][lt]);
    else {
        int mid = (lt + rt) / 2;
        init(c, 2*cur, lt, mid);
        init(c, 2*cur+1, mid, rt);
        tree[c][cur] = prop(tree[c][2*cur], tree[c][2*cur+1], lt, mid, rt);
    }
}

void update(int c, int cur, int lt, int rt, int p, int v) {
    if (lt + 1 == rt) tree[c][cur] = data(v, lt + v, v);
    else {
        int mid = (lt + rt) / 2;
        if (p < mid) update(c, 2*cur, lt, mid, p, v);
        else update(c, 2*cur+1, mid, rt, p, v);
        tree[c][cur] = prop(tree[c][2*cur], tree[c][2*cur+1], lt, mid, rt);
    }
}

int main() {
    ios :: sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        for (int j=0; j<MAXLG; j++)
            b[j][i] = a[i] & 1<<j;
    }

    for (int i=0; i<MAXLG; i++)
        init(i, 1, 0, n);

    for (int i=0; i<m; i++) {
        int p, v;
        cin >> p >> v;
        p--;
        ll ans = 0;
        for (int j=0; j<MAXLG; j++) {
            update(j, 1, 0, n, p, bool(v & 1<<j));
            ans += tree[j][1].sum * (1<<j);
        }
        cout << ans << '\n';
    }

    return 0;
}