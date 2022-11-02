#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define F first
#define S second
int t, n, a[200001], b[200001], m, ans;
ll total;
vi winners;
map<int, int> tokens;

void solve() {
    cin >> n;
    tokens.clear();
    for (int i = 0; i < n; i++) {cin >> a[i]; b[i]=a[i];}
    sort(b, b+n);
    int lo=0, hi=n, mid;
    while (lo <= hi) {
        mid = (lo+hi)/2;
        total = b[mid];
        bool works = true;
        for (int i = 0; i < n; i++) {
            if (i==mid) continue;
            if (b[i]>total) {works=false; break;}
            total += b[i];
        }
        if (works) {
            m = b[mid];
            hi = mid-1;
        } else lo = mid+1;
    }
    ans = 0;
    winners.clear();
    for (int i = 0; i < n; i++) {
        if (a[i] >= m) {
            ans++;
            winners.pb(i+1);
        }
    }
    cout << ans << '\n';
    for (int i = 0; i < winners.size(); i++) cout << winners[i] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}