# include <bits/stdc++.h>

using namespace std;

const int MAXN = 200010;

typedef long long ll;
typedef pair<ll,ll> pll;
ll l[MAXN], r[MAXN];
pair<pll,int> a[MAXN];
pair<ll,int> c[MAXN];
int ans[MAXN];

int main() {
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m; n = n - 1;
    for(int i = 0; i <= n; ++i) cin >> l[i] >> r[i];
    for(int i = 0; i < n; ++i) 
        a[i] = make_pair(pll(l[i+1] - r[i], r[i+1] - l[i]), i);
    for(int i = 0; i < m; ++i) cin >> c[i].first, c[i].second = i;
    sort(a, a + n); sort(c, c + m);
    int k = 0, cnt = 0;
    set< pair<ll,int> > e;
    for(int i = 0; i < m; ++i) {
        for(;k < n && a[k].first.first <= c[i].first;k++) 
            e.insert(make_pair(a[k].first.second, a[k].second));
        while(!e.empty() && e.begin()->first < c[i].first)
            e.erase(e.begin());
        if(e.empty()) continue;
        ans[e.begin()->second] = c[i].second;
        e.erase(e.begin()); cnt++;
    }
    if(cnt == n) {
        puts("Yes");
        for(int i = 0; i < n; ++i)
            printf("%d%c", ans[i] + 1, " \n"[i==n-1]);
    } else puts("No");
    return 0;
}