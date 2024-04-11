
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
string t = "101";

int ask(string &s) {
    // int x = 0;
    // rep(i, 0, n) {
    //     x += (s[i] != t[i]);
    // }
    cout << "? " << s << endl;
    // cout << x << endl;
    int x;
    cin >> x;
    return x;
}
void answer(int p0, int p1) {
    cout << "! " << p0 + 1 << ' ' << p1 + 1 << endl;
}

pii solve() {
    string s(n, '0');
    int L = 0, R = n - 1;
    int d = ask(s);
    int p0 = -2, p1 = -2;
    while(L < R) {
        int m = (L + R) / 2;
        fill(s.begin() + L, s.begin() + m + 1, '1');
        int x = ask(s);
        fill(s.begin() + L, s.begin() + m + 1, '0');
        if(x == d - (m - L + 1)) {
            p1 = L;
            L = m + 1;
        }else if(x == d + (m - L + 1)) {
            p0 = L;
            L = m + 1;
        }else {
            R = m;
        }
    }
    if(p0 < 0) p0 = L;
    if(p1 < 0) p1 = L;
    return {p0, p1};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int p0, p1;
    tie(p0, p1) = solve();
    answer(p0, p1);
}