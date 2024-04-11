
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
    string s; cin >> s;
    int n = s.length();
    string best = "";
    rep(mask, 1, 1 << n) {
        string t;
        rep(i, 0, n) {
            if(mask >> i & 1) t.push_back(s[i]);
        }
        string t2(all(t));
        reverse(all(t2));
        if(t == t2 && t > best) {
            best = t;
        }
    }
    cout << best << '\n';
}