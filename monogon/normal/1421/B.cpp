
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

const int N = 205;
string s[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int n;
        cin >> n;
        rep(i, 0, n) {
            cin >> s[i];
        }
        int cnt = (s[0][1] == '0') + (s[1][0] == '0') + (s[n - 1][n - 2] == '1') + (s[n - 2][n - 1] == '1');
        vector<pii> ve;
        if(cnt <= 2) {
            if(s[0][1] == '0') ve.emplace_back(1, 2);
            if(s[1][0] == '0') ve.emplace_back(2, 1);
            if(s[n - 1][n - 2] == '1') ve.emplace_back(n, n - 1);
            if(s[n - 2][n - 1] == '1') ve.emplace_back(n - 1, n);
        }else {
            if(s[0][1] == '1') ve.emplace_back(1, 2);
            if(s[1][0] == '1') ve.emplace_back(2, 1);
            if(s[n - 1][n - 2] == '0') ve.emplace_back(n, n - 1);
            if(s[n - 2][n - 1] == '0') ve.emplace_back(n - 1, n);
        }
        cout << sz(ve) << '\n';
        for(auto &pa : ve) {
            int u, v;
            tie(u, v) = pa;
            cout << u << ' ' << v << '\n';
        }
    }
}