
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

const int N = 55;
int t, n, m, b[N];
string s;
int cnt[26], d[N];
bool used[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> s >> m;
        n = s.length();
        fill(cnt, cnt + 26, 0);
        fill(used, used + m, false);
        rep(i, 0, n) {
            cnt[s[i] - 'a']++;
        }
        rep(i, 0, m) {
            cin >> b[i];
        }
        fill(all(s), '$');
        fill(d, d + m, 0);
        for(int c = 25; c >= 0; c--) {
            vi ve;
            rep(i, 0, m) {
                if(!used[i] && d[i] == b[i]) {
                    ve.push_back(i);
                }
            }
            if(sz(ve) > cnt[c]) continue;
            for(int i : ve) {
                s[i] = c + 'a';
                used[i] = true;
                rep(j, 0, m) {
                    d[j] += abs(j - i);
                }
            }
        }
        cout << s.substr(0, m) << '\n';
    }
}