
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

ll k;
string s = "codeforces";
ll a[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> k;
    ll val = 1;
    fill(a, a + 10, 1);
    while(val < k) {
        int idx = min_element(a, a + 10) - a;
        a[idx]++;
        val = 1;
        rep(i, 0, 10) {
            val *= a[i];
        }
    }
    rep(i, 0, 10) {
        while(a[i]--) {
            cout << s[i];
        }
    }
    cout << '\n';
}