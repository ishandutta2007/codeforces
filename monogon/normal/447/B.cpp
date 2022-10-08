
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

string s;
int n, k;
ll w[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.length();
    cin >> k;
    rep(c, 0, 26) {
        cin >> w[c];
    }
    int mx = *max_element(w, w + 26);
    ll cost = 0;
    rep(i, 1, n + 1) {
        cost += w[s[i - 1] - 'a'] * i;
    }
    rep(i, 0, k) {
        cost += mx * (n + i + 1);
    }
    cout << cost << '\n';
}