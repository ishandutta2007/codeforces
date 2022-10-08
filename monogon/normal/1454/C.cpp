
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
        vector<vi> ve(n + 1);
        rep(i, 0, n) {
            int a;
            cin >> a;
            ve[a].push_back(i + 1);
        }
        int ans = 1e9;
        rep(i, 1, n + 1) {
            if(ve[i].empty()) continue;
            int pre = 0;
            int cnt = 0;
            for(int j : ve[i]) {
                if(j > pre + 1) cnt++;
                pre = j;
            }
            if(ve[i].back() != n) cnt++;
            ans = min(ans, cnt);
        }
        cout << ans << '\n';
    }
}