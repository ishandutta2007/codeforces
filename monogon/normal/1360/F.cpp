
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

const int N = 11;
int t, n, m;
string s[N];

bool check(string &t) {
    rep(i, 1, n) {
        int dif = 0;
        rep(j, 0, m) {
            dif += (t[j] != s[i][j]);
        }
        if(dif > 1) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        rep(i, 0, n) {
            cin >> s[i];
        }
        if(check(s[0])) {
            cout << s[0] << '\n';
            goto lab;
        }
        rep(i, 0, m) {
            char ch = s[0][i];
            for(char c = 'a'; c <= 'z'; c++) {
                s[0][i] = c;
                if(check(s[0])) {
                    cout << s[0] << '\n';
                    goto lab;
                }
            }
            s[0][i] = ch;
        }
        cout << "-1\n";
        lab:;
    }
}