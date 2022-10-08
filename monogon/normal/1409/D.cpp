
#include <bits/stdc++.h>

#define ll long long
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define vi vector<int>

using namespace std;

int sumdig(ll n) {
    int s = 0;
    while(n > 0) {
        s += (n % 10);
        n /= 10;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        ll n, s;
        cin >> n >> s;
        string str;
        ll x = n;
        while(x > 0) {
            str.push_back('0' + (x % 10));
            x /= 10;
        }
        reverse(all(str));
        ll ans = 1;
        rep(i, 0, (int) str.length()) ans *= 10;
        if(sumdig(n) <= s) {
            cout << "0\n";
            continue;
        }
        ll nn = 0;
        for(char c : str) {
            int dig = c - '0';
            nn = 10 * nn + dig;
            if(sumdig(nn + 1) <= s) {
                ans = nn + 1;
            }
        }
        while(ans < n) ans *= 10;
        cout << ans - n << '\n';
    }
}