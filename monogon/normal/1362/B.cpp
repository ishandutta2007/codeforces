
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

const int N = 1030;
int t, n, s[N], s2[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        rep(i, 0, n) cin >> s[i];
        sort(s, s + n);
        rep(mask, 1, 1024) {
            rep(i, 0, n) s2[i] = s[i] ^ mask;
            sort(s2, s2 + n);
            bool flag = false;
            rep(i, 0, n) flag |= (s[i] != s2[i]);
            if(!flag) {
                cout << mask << '\n';
                goto jail;
            }
        }
        cout << "-1\n";
        jail:;
    }
}