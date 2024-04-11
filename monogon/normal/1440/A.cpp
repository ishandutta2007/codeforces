
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
        ll c0, c1, h;
        string s;
        cin >> n >> c0 >> c1 >> h >> s;
        c0 = min(c0, h + c1);
        c1 = min(c1, h + c0);
        ll ans = 0;
        for(char c : s) {
            ans += (c == '0' ? c0 : c1);
        }
        cout << ans << '\n';
    }
}