#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
const int N = 2e5 + 10, V = 2e5;
int n, m, x;
int a[N], b[N];
int stk[N], top = 0;
int lson[N], rson[N], mxa[N], mxb[N], mna[N], mnb[N];
int t[N];
vector<int> q[N], g[N];
// a  <= x - b
// a  > x - nb
// x - nb + 1 <= a <= x - b

// b >= x + 1 - na
void add(int x, int v) {
    for(int i = x; i <= V; i += i & (-i)) t[i] += v;
    return;
}

int sum(int x) {
    x = min(x, V);
    int res = 0;
    for(int i = x; i > 0; i -= i & (-i)) res += t[i];
    return res;
}

void dfs(int x, int mx[], int a[]) {
    if(x == -1) return;
    mx[x] = a[x];
    dfs(lson[x], mx, a), dfs(rson[x], mx, a);
    mx[x] = max(mx[x], mx[lson[x]]);
    mx[x] = max(mx[x], mx[rson[x]]);
    return;
}

int main() {
    // freopen("1.in", "r", stdin);
    cin >> n >> m >> x;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[0] = a[n + 1] = V + 1;
    for(int i = 0; i <= n + 1; i++) {
        lson[i] = rson[i] = -1;
        while(top && a[stk[top]] > a[i]) {
            rson[stk[top]] = lson[i];
            lson[i] = stk[top];
            top--;
        }
        stk[++top] = i;
    }
    while(top > 1) rson[stk[top - 1]] = stk[top], top--;
    dfs(stk[1], mxa, a);
    for(int i = 1; i <= n; i++) {
        mna[i] = a[i];
        mna[i] = max(mna[i], min(mxa[lson[i]], mxa[rson[i]]));
    }
    top = 0;
    b[0] = b[m + 1] = V + 1;
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    for(int i = 0; i <= m + 1; i++) {
        lson[i] = rson[i] = -1;
        while(top && b[stk[top]] > b[i]) {
            rson[stk[top]] = lson[i];
            lson[i] = stk[top];
            top--;
        }
        stk[++top] = i;
    }
    while(top > 1) rson[stk[top - 1]] = stk[top], top--;
   dfs(stk[1], mxb, b);
    for(int i = 1; i <= m; i++) {
        mnb[i] = b[i];
        mnb[i] = max(mnb[i], min(mxb[lson[i]], mxb[rson[i]]));
    }
    for(int i = 1; i <= m; i++) {
        int l = max(1, x - mnb[i] + 1), r = min(V, x - b[i]) + 1;
        if(l < r) {
            q[l].push_back(i), q[r].push_back(-i);
        }
    }
    for(int i = 1; i <= n; i++) {
        g[a[i]].push_back(i);
    }
    i64 ans = 0;
    for(int i = 1; i <= V; i++) {
        for(int &v : q[i]) {
            if(v > 0) {
                add(b[v], 1);
            } else {
                add(b[- v], - 1);
            }
        }
        for(int &v : g[i]) {
            ans += sum(V) - sum(x - mna[v]);
        }
    }
    cout << ans << endl;
    return 0;
}