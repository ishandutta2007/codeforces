
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

int t;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> s;
        int n = s.length();
        vector<string> ve;
        rep(i, 0, n) {
            if(s[i] != '0') {
                string t;
                t.push_back(s[i]);
                rep(j, 0, n - i - 1) {
                    t.push_back('0');
                }
                ve.push_back(t);
            }
        }
        cout << sz(ve) << '\n';
        for(auto &t : ve) {
            cout << t << ' ';
        }
        cout << '\n';
    }
}