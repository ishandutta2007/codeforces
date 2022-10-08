
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

const int N = 35;
int t, n, k, a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        rep(i, 0, n) {
            cin >> a[i];
        }
        rep(i, 0, n) {
            cin >> b[i];
        }
        sort(a, a + n);
        sort(b, b + n);
        rep(i, 0, k) {
            if(a[i] < b[n - i - 1]) {
                swap(a[i], b[n - i - 1]);
            }else break;
        }
        cout << accumulate(a, a + n, 0) << '\n';
    }
}