
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

const int N = 1005;
int t, n;
string s;
int pref[N], pref2[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> s;
        n = s.length();
        int op = n;
        rep(i, 1, n + 1) {
            pref[i] = pref[i - 1] + (s[i - 1] == '1');
            pref2[i] = pref2[i - 1] + (s[i - 1] == '0');
        }
        rep(i, 0, n + 1) {
            op = min(op, pref[i] + pref2[n] - pref2[i]);
            op = min(op, pref2[i] + pref[n] - pref[i]);
        }
        cout << op << '\n';
    }
}