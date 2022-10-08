
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// 0 problems => does it count?
// 1 problem => anything works
// 2 problems => let's make a histogram
// for a number x, count sum(previous numbers) - sum(previous divisors)

// 3 problems => count all possible triples, and subtract cases where some of them divide each other
// (a, b, c) where a < b < c. Cases:
// 1. b | c
// 2. a | c
// 3. a | b
// 4.

// 2 problems?
// (a/b) = () - (a|b)

// PIE
// (a/b/c) = () - (a|b) - (b|c) - (a|c) + (a|b, a|c) + (a|c, b|c)

const int N = 2e5 + 5;
int t, n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> ve;
        rep(i, 0, n) {
            cin >> a[i];
            ve.push_back(a[i]);
        }
        sort(all(ve));
        ve.erase(unique(all(ve)), ve.end());
        reverse(all(ve));
        int d = min(150, sz(ve));
        int ans = ve[0];
        rep(i, 0, d) {
            rep(j, i + 1, d) {
                if(ve[i] % ve[j] != 0) {
                    ans = max(ans, ve[i] + ve[j]);
                    rep(k, j + 1, d) {
                        if(ve[i] % ve[k] != 0 && ve[j] % ve[k] != 0) {
                            ans = max(ans, ve[i] + ve[j] + ve[k]);
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}