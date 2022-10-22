#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define ull unsigned long long
#define db double
#define x first
#define y second
#define vi vector<int>
using namespace std;
int n, a[2010], fa[2010];
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]); }
void merge(int x, int y) {fa[find(x)] = find(y); }
int check() {
    FOR(i, 1, n) fa[i] = i;
    FOR(i, 0, 29) {
        int rt = -1;
        FOR(j, 1, n) if(a[j] >> i & 1) {
            if(rt != -1) merge(rt, j);
            rt = j;
        }
    }
    FOR(i, 2, n) if(find(i - 1) != find(i)) return 0;
    return 1;
}
void output(int ans) {
    cout << ans << "\n";
    FOR(i, 1, n) cout << a[i] <<" ";
    cout << "\n";
}
void solve() {
    cin >> n;
    int ans = 0;
    FOR(i, 1, n) {
        cin >> a[i];
        if(!a[i]) a[i]++, ans++;
    }
    int mxl = 0;
    FOR(i, 1, n) mxl = max(mxl, a[i] & (-a[i]));
    if(check()) return output(ans);
    FOR(i, 1, n) {
        a[i]++;
        if(check()) return output(ans + 1);
        a[i] -= 2;
        if(check()) return output(ans + 1);
        a[i]++;
    }
    int cnt = 0;
    FOR(i, 1, n) if((a[i] & (-a[i])) == mxl) {
        if(cnt == 0) a[i]++, cnt++;
        else if(cnt == 1) a[i]--, cnt++;
    }
    output(ans + 2);
    return;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; solve());
    return 0;
}