
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
        string s;
        cin >> n >> s;
        bool flag = false;
        rep(i, 0, n) {
            if(s[i] != s[(i + n - 1) % n]) {
                rotate(s.begin(), s.begin() + i, s.end());
                flag = true;
                break;
            }
        }
        if(!flag) {
            cout << (n + 2) / 3 << '\n';
            continue;
        }
        int cnt = 1;
        int ans = 0;
        rep(i, 1, n) {
            if(s[i] == s[(i + n - 1) % n]) {
                cnt++;
            }else {
                ans += cnt / 3;
                cnt = 1;
            }
        }
        ans += cnt / 3;
        cout << ans << '\n';
    }
}