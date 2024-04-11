
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

const int N = 8005;
int t, n, a[N];
bool b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        rep(i, 0, n) {
            cin >> a[i];
        }
        fill(b, b + n + 1, false);
        rep(i, 0, n) {
            int sum = a[i];
            rep(j, i + 1, n) {
                sum += a[j];
                if(sum > n) break;
                b[sum] = true;
            }
        }
        int cnt = 0;
        rep(i, 0, n) {
            cnt += b[a[i]];
        }
        cout << cnt << '\n';
    }
}