
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

int t, n, k;
string s;
int cnt[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k >> s;
        fill(cnt, cnt + 26, 0);
        for(char c : s) cnt[c - 'a']++;
        int best = 1;
        rep(m, 1, n + 1) {
            int g = gcd(m, k);
            int si = m / g;
            int num = 0;
            rep(c, 0, 26) {
                num += cnt[c] / si;
            }
            if(num >= g) {
                best = m;
            }
        }
        cout << best << '\n';
    }
}