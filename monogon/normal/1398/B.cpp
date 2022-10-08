
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
        string s;
        cin >> s;
        s += '0';
        int n = s.length();
        int cnt = 0;
        vi vec;
        rep(i, 0, n) {
            if(s[i] == '1') {
                cnt++;
            }else if(cnt > 0) {
                vec.push_back(cnt);
                cnt = 0;
            }
        }
        ll ans = 0;
        sort(all(vec));
        int i = sz(vec) - 1;
        while(i >= 0) {
            ans += vec[i];
            i -= 2;
        }
        cout << ans << '\n';
    }
}