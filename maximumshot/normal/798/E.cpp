#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 5e5 + 5;

int n;
int p[N];
int q[N];

pii tree[4 * N];

void build(int v, int tl, int tr) {
    if(tl == tr) {
        tree[v] = make_pair(q[tl], tl);
    }else {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    }
}

void put(int v, int tl, int tr, int pos, int val) {
    if(tl == tr) {
        tree[v] = make_pair(val, pos);
    }else {
        int tm = (tl + tr) >> 1;
        if(pos <= tm) {
            put(v << 1, tl, tm, pos, val);
        }else {
            put(v << 1 | 1, tm + 1, tr, pos, val);
        }
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    }
}

pii get(int v, int tl, int tr, int l, int r) {
    if(l <= tl && tr <= r) {
        return tree[v];
    }else {
        int tm = (tl + tr) >> 1;
        pii res = make_pair(-inf, -1);
        if(l <= tm) {
            res = max(res, get(v << 1, tl, tm, l, r));
        }
        if(r > tm) {
            res = max(res, get(v << 1 | 1, tm + 1, tr, l, r));
        }
        return res;
    }
}

int res[N];
bool used[N];

void dfs(int v) {
    used[v] = 1;
    put(1, 1, n, v, -inf);
    if(q[v] <= n && !used[q[v]]) {
        dfs(q[v]);
    }
    while(1 < p[v]) {
        pii tmp = get(1, 1, n, 1, p[v] - 1);
        if(tmp.first <= v) break;
        if(!used[tmp.second]) {
            dfs(tmp.second);
        }
    }
    static int cur = 1;
    res[v] = cur++;
}

int main() {

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        q[i] = n + 1;
    }

    for(int i = 1;i <= n;i++) {
        scanf("%d", &p[i]);
        if(p[i] == -1) {
            p[i] = n + 1;
        }
        q[p[i]] = i;
    }

    build(1, 1, n);

    for(int i = 1;i <= n;i++) {
        if(!used[i]) {
            dfs(i);
        }
    }

    for(int i = 1;i <= n;i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

//    vec< char > vis(n + 1);

//    for(int i = 1;i <= n;i++) {
//        int t = -1;
//        for(int j = 1;j <= n;j++) {
//            if(vis[j]) continue;
//            if(res[i] < res[j]) {
//                t = j;
//                break;
//            }
//        }
//        cout << t << " ";
//        if(t != -1) {
//            vis[t] = 1;
//        }
//    }

//    cout << "\n";

    return 0;
}