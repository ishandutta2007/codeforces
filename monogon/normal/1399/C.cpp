
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
        map<int, int> ma;
        rep(i, 0, n) {
            int w;
            cin >> w;
            ma[w]++;
        }
        int ans = 0;
        rep(s, 0, 2 * n + 1) {
            int k = 0;
            rep(i, 0, s / 2 + 1) {
                if(i == s - i) {
                    k += ma[i] / 2;
                }else {
                    k += min(ma[i], ma[s - i]);
                }
            }
            ans = max(ans, k);
        }
        cout << ans << '\n';
    }
}