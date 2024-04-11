
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
    string s;
    cin >> s;
    ll h = (s[0] - '0') * 10 + s[1] - '0';
    ll m = (s[3] - '0') * 10 + s[4] - '0';
    h %= 12;
    cout << fixed << setprecision(10);
    cout << ((h + (1.0 * m / 60)) * 360 / 12) << ' ' << m * 360 / 60 << '\n';
}