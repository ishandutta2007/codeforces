#include <bits/stdc++.h>

using namespace std;

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define pi pair<int, int>
#define mp make_pair
#define F first
#define S second
int t, n;
vi s, cnt;

void solve() {
    cin >> n;
    s.clear();
    s.rsz(n);
    F0R(i, n) cin >> s[i];
    cnt.clear();
    cnt.rsz(n, 0);
    ll ans = 0;
    F0R(i, n) {
        if (i < n-1 && i+s[i]>=n) {
            int temp = cnt[i];
            cnt[i] = max(0, cnt[i]-s[i]-i+n-1);
            ans += max(0, i+s[i]-temp-n+1);
            s[i] = n-1-i;
        } else if (i==n-1) {
            ans += max(0, i+s[i]-cnt[i]-n);
            s[i]=1;
        }
        while (s[i]>1) {
            if (i+s[i]<n) cnt[i+s[i]]++;
            s[i]--;
            if (cnt[i]==0) ans++;
            else cnt[i]--;
        }
        if (i<n-1) cnt[1+i] += cnt[i];
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}