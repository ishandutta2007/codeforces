
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
    int n, p;
    string s;
    cin >> n >> p >> s;
    vi cnt(p, 0);
    vi bad(1 << p);
    rep(c1, 0, p) rep(c2, 0, p) {
        int a;
        cin >> a;
        if(a == 0) {
            int j = 0;
            int mask = 0;
            fill(all(cnt), 0);
            rep(i, 0, n) {
                if(s[i] - 'a' == c2 && j != 0 && (~mask >> c1 & 1) && (~mask >> c2 & 1)) {
                    bad[mask]++;
                    bad[mask ^ (1 << c1)]--;
                    if(c1 != c2) {
                        bad[mask ^ (1 << c2)]--;
                        bad[mask ^ (1 << c1) ^ (1 << c2)]++;
                    }
                }
                if(cnt[s[i] - 'a'] == 0) mask ^= (1 << (s[i] - 'a'));
                cnt[s[i] - 'a']++;
                if(s[i] - 'a' == c1) {
                    while(j <= i) {
                        cnt[s[j] - 'a']--;
                        if(cnt[s[j] - 'a'] == 0) {
                            mask ^= (1 << (s[j] - 'a'));
                        }
                        j++;
                    }
                }
            }
        }
    }
    fill(all(cnt), 0);
    rep(i, 0, n) cnt[s[i] - 'a']++;
    rep(i, 0, p) {
        rep(s, 0, 1 << p) {
            if(s >> i & 1) {
                bad[s] += bad[s ^ (1 << i)];
            }
        }
    }
    int ans = n;
    queue<int> Q;
    Q.push(0);
    vector<bool> vis(1 << p, false);
    vis[0] = true;
    while(!Q.empty()) {
        int s = Q.front(); Q.pop();
        if(bad[s] > 0) continue;
        int c = 0;
        rep(i, 0, p) {
            if((~s >> i & 1)) {
                c += cnt[i];
                if(!vis[s ^ (1 << i)]) {
                    vis[s ^ (1 << i)] = true;
                    Q.push(s ^ (1 << i));
                }
            }
        }
        ans = min(ans, c);
    }
    cout << ans << '\n';
}