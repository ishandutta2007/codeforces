#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define sz(a) int((a).size())
#define vi vector<int>
typedef long long ll;
typedef double db;
const int N = 1e5 + 10, M = 5;
int n, m, id[N][1 << M];
struct node {
    int a[M], n;
    node() {n = 0, memset(a, 0, sizeof(a)); }
    void push_back(int v) {
        a[n++] = v;
    }
    friend bool operator < (const node a, const node b) {
        for(int i = 0; i < m; i++) if(a.a[i] != b.a[i]) return a.a[i] < b.a[i];
        return 0;
    }
    friend bool operator == (const node a, const node b) {
        for(int i = 0; i < m; i++) if(a.a[i] != b.a[i]) return 0;
        return 1;
    }
};
node b[N << M], tmp[N][1 << M];
vector<int> a[N];
int w[N], order[N];
int cnt[N << M];
int stk[N];
int calc(int x) {
    int sum = 0;
    for(int i = 1; i < (1 << m); i++) {
        sum += (__builtin_parity(i) ? 1 : -1) * cnt[id[x][i]];
    }
    return sum;
}
void insert(int x, int v) {
    for(int i = 1; i < (1 << m); i++) {
        cnt[id[x][i]] += v;
    }
    return;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        a[i].resize(m);
        for(int j = 0; j < m; j++) cin >> a[i][j];
        sort(a[i].begin(), a[i].end());
        cin >> w[i], order[i] = i;
    }
    int tot = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < (1 << m); j++) {
            for(int k = 0; k < m; k++) if(j >> k & 1) tmp[i][j].push_back(a[i][k]);
            b[++tot] = tmp[i][j];
        }
    }
    sort(b + 1, b + tot + 1);
    tot = unique(b + 1, b + tot + 1) - (b + 1);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < (1 << m); j++) id[i][j] = lower_bound(b + 1, b + tot + 1, tmp[i][j]) - b;
    }
    sort(order + 1, order + n + 1, [&](int x, int y) {return w[x] < w[y]; });
    int top = 0;
    int ans = INT_MAX;
    for(int i = 1; i <= n; i++) {
        int x = order[i];
        int lst = -1;
        while(top - calc(x) >= 1) lst = stk[top], insert(stk[top], -1), top--;
        if(lst != -1) ans = min(ans, w[lst] + w[x]);
        insert(x, 1), stk[++top] = x;
    }
    if(ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}