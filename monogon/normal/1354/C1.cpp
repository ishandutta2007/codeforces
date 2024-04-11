
#define _USE_MATH_DEFINES
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

int t, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    cout << fixed << setprecision(8);
    while(t--) {
        cin >> n;
        cout << 1.0 / tan(M_PI / (2 * n)) << '\n';
    }
}