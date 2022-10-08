
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

const int N = 1e5 + 5;
int t, n, k;
string s;
string S[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k >> s;
        sort(all(s));
        rep(i, 0, k) {
            S[i].clear();
            S[i].push_back(s[i]);
        }
        if(S[0][0] == S[k - 1][0]) {
            int i = k;
            for(; i < n; i++) {
                if(s[i] == s.back()) break;
                S[0].push_back(s[i]);
            }
            if(i == k) {
                for(; i < n; i++) {
                    S[i % k].push_back(s[i]);
                }
            }else {
                for(; i < n; i++) {
                    S[0].push_back(s[i]);
                }
            }
        }else {
            rep(i, k, n) {
                S[0].push_back(s[i]);
            }
        }
        string mx = S[0];
        rep(i, 0, k) {
            // cout << S[i] << " ";
            mx = max(mx, S[i]);
        }
        // cout << "\n";
        cout << mx << '\n';
    }
}