
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
        vi a(n);
        vector<vi> pos(n + 1);
        rep(i, 0, n) {
            cin >> a[i];
            pos[a[i]].push_back(i);
        }
        vi ans(n + 1, -1);
        int y = n + 1;
        rep(x, 1, n + 1) {
            if(pos[x].empty()) continue;
            int val = max(pos[x][0], n - 1 - pos[x].back()) + 1;
            rep(i, 1, sz(pos[x])) {
                val = max(val, pos[x][i] - pos[x][i - 1]);
            }
            rep(i, val, y) {
                ans[i] = x;
            }
            y = min(y, val);
        }
        rep(i, 1, n + 1) {
            cout <<  ans[i] << ' ';
        }
        cout << '\n';
    }
}