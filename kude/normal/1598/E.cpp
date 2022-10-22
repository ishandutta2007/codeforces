#include<bits/stdc++.h>
using namespace std;
#define rep(i,n)for (int i = 0; i < int(n); ++i)
#define rrep(i,n)for (int i = int(n)-1; i >= 0; --i)
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
const int dx[2] = {1, 0};
const int dy[2] = {0, 1};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, m, q;
        cin >> n >> m >> q;
        vector<set<int>> d;
        vector<vector<vector<pair<int, int>>>> data_ij(n, vector<vector<pair<int, int>>>(m));
        vector<vector<char>> state(n, vector<char>(m));
        ll now = 0;
        auto count = [](ll x, ll y) {
            x++;
            if (y - x < 2) return 0LL;
            if (x & 1) x++;
            ll n = y - x;
            if (n % 2 == 0) {
                n /= 2;
                return n * n;
            }
            else return (n + 1) / 2 * ((n - 1) / 2);
        };
        rep(k0, 2) {
            for(int i = n - 1, j = 0; j < m;) {
                int idx = d.size();
                d.resize(idx + 1);
                auto& st = d[idx];
                st.insert(-1);
                int pos = 0;
                for(int x = i, y = j, k = k0; x < n && y < m; x += dx[k], y += dy[k], k ^= 1) {
                    data_ij[x][y].emplace_back(idx, pos++);
                }
                st.insert(pos);
                now += count(-1, pos);
                if (i) i--;
                else j++;
            }
        }
        now += n * m;
        while(q--) {
            int i, j;
            cin >> i >> j;
            i--, j--;
            if (state[i][j]) {
                now++;
                for(auto [idx, pos]: data_ij[i][j]) {
                    auto& st = d[idx];
                    auto it = st.lower_bound(pos);
                    auto pit = prev(it);
                    auto nit = next(it);
                    now -= count(*pit, *it);
                    now -= count(*it, *nit);
                    now += count(*pit, *nit);
                    st.erase(it);
                }
            } else {
                now--;
                for(auto [idx, pos]: data_ij[i][j]) {
                    auto& st = d[idx];
                    auto nit = st.lower_bound(pos);
                    auto pit = prev(nit);
                    now -= count(*pit, *nit);
                    now += count(*pit, pos);
                    now += count(pos, *nit);
                    st.insert(pos);
                }
            }
            state[i][j] ^= 1;
            cout << now << '\n';
        }
    }
}