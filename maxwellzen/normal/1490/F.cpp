#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define F first
#define S second
int t, n, a, ans, cans, lo, hi, mid;
map<int, int> freq, ft;
vi f;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {cin >> a; freq[a]++;}
    lo = 0; hi = 0;
    for (auto p : freq) {ft[p.S]++; hi = max(hi, p.S);}
    freq.clear();
    ans = INT_MAX;
    for (int mid = 0; mid <= hi; mid++) {
//        mid = (lo+hi)/2;
        cans = 0;
        for (auto p : ft) {
            if (p.F<mid) cans += p.F*p.S;
            else cans += (p.F - mid)*p.S;
        }
        ans = min(ans, cans);
    }
    cout << ans << '\n';
    ft.clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}