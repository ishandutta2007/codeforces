#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

bool is_last[200100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        string s;
        cin >> s;
        int n = s.size();
        VI a(n);
        rep(i, n) a[i] = s[i] - 'a';
        {
            bool seen[26] = {};
            rrep(i, n) {
                if (!seen[a[i]]) {
                    seen[a[i]] = true;
                    is_last[i] = true;
                } else {
                    is_last[i] = false;
                }
            }
        }
        string ans;
        {
            bool inserted[26] = {};
            auto mycmp = [&](int i, int j) {
                return a[i] < a[j] || a[i] == a[j] && i > j;
            };
            priority_queue<int, VI, decltype(mycmp)> q(mycmp);
            int l = -1;
            rep(i, n) {
                int x = a[i];
                if (inserted[x]) continue;
                q.push(i);
                if (is_last[i]) {
                    while(!q.empty()) {
                        int j = q.top(); q.pop();
                        if (j < l) continue;
                        int y = a[j];
                        if (y < x) continue;
                        if (inserted[y]) continue;
                        inserted[y] = true;
                        l = j;
                        ans.push_back('a' + y);
                        if (y == x) break;
                    }
                    assert(inserted[x]);
                }
            }
        }
        cout << ans << '\n';
    }
}