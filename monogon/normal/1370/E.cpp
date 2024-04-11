
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
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

int n;
string s, t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s >> t;
    int cnt = 0;
    rep(i, 0, n) cnt += (s[i] == '0');
    rep(i, 0, n) cnt -= (t[i] == '0');
    if(cnt != 0) {
        cout << "-1\n";
        return 0;
    }
    string s2;
    rep(i, 0, n) {
        if(s[i] != t[i]) {
            s2.push_back(s[i]);
        }
    }
    if(s2.empty()) {
        cout << "0\n";
        return 0;
    }
    int mx = 0;
    n = s2.length();
    cnt = 0;
    rep(i, 0, 2 * n) {
        if(s2[i % n] == '0') {
            cnt++;
        }else if(cnt > 0) {
            cnt--;
        }
        mx = max(mx, cnt);
    }
    cout << mx << '\n';
}