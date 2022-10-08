
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

const int N = 2e5 + 5, T = 101;
int n, m, t[N], arr[T];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> t[i];
        int cnt = 0, sum = 0, ans = 0;
        rep(j, 1, T) {
            if(j * arr[j] + cnt + t[i] > m) {
                ans = i - sum - (m - cnt - t[i]) / j;
                break;
            }
            sum += arr[j];
            cnt += j * arr[j];
        }
        cout << ans << ' ';
        arr[t[i]]++;
    }
    cout << '\n';
}