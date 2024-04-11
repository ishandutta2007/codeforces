
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int n;
        cin >> n;
        vector<bool> vis(2 * n + 1, false);
        vi A(n), B(n);
        rep(i, 0, n) {
            cin >> B[i];
            vis[B[i]] = true;
        }
        sort(all(B));
        int idx = 0;
        rep(i, 1, 2 * n + 1) {
            if(!vis[i]) {
                A[idx++] = i;
            }
        }
        int minx = -1, maxx = n;
        rep(i, 0, n) {
            int j = lower_bound(all(A), B[i]) - A.begin();
            // i + n - x >= j
            // x <= n + i - j
            maxx = min(maxx, n + i - j);
            // i - x <= j - 1
            // x >= i - j + 1
            minx = max(minx, i - j + 1);
        }
        cout << max(0, maxx - minx + 1) << '\n';
    }
}