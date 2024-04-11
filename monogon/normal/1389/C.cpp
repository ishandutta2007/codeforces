
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

int check(const string &s, char c1, char c2) {
    bool f = false;
    int cnt = 0;
    int n = s.length();
    rep(i, 0, n) {
        if(f) {
            if(s[i] == c1) {
                f = !f;
                cnt++;
            }
        }else {
            if(s[i] == c2) {
                f = !f;
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        string s;
        cin >> s;
        int n = s.length();
        int ans = 0;
        for(char c = '0'; c <= '9'; c++) {
            ans = max(ans, check(s, c, c));
            for(char c2 = '0'; c2 <= '9'; c2++) {
                int val = check(s, c, c2);
                if(val % 2 == 1) val--;
                ans = max(ans, val);
            }
        }
        cout << n - ans << '\n';
    }
}