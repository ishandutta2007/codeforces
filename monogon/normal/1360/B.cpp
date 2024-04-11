
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

const int N = 55;
int t, n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        rep(i, 0, n) cin >> a[i];
        sort(a, a + n);
        int m = INT_MAX;
        rep(i, 0, n - 1) {
            m = min(m, a[i + 1] - a[i]);
        }
        cout << m << '\n';
    }
}