
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
    int n, q;
    string s;
    cin >> n >> q >> s;
    int cnt = 0;
    rep(i, 0, n - 2) {
        cnt += (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c');
    }
    while(q--) {
        int i; char c;
        cin >> i >> c;
        i--;
        rep(j, 0, 3) {
            if(i - j >= 0 && i - j + 2 < n) {
                cnt -= (s[i - j] == 'a' && s[i - j + 1] == 'b' && s[i - j + 2] == 'c');
            }
        }
        s[i] = c;
        rep(j, 0, 3) {
            if(i - j >= 0 && i - j + 2 < n) {
                cnt += (s[i - j] == 'a' && s[i - j + 1] == 'b' && s[i - j + 2] == 'c');
            }
        }
        cout << cnt << '\n';
    }
}