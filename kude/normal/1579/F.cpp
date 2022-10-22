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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n, d;
        cin >> n >> d;
        VI a(n);
        rep(i, n) cin >> a[i];
        vector<char> visited(n);
        auto dec = [&](int i) {
            i -= d;
            if (i < 0) i += n;
            return i;
        };
        auto inc = [&](int i) {
            i += d;
            if (i >= n) i -= n;
            return i;
        };
        int ans = 0;
        rep(i, n) if (!visited[i] && a[i] == 1) {
            visited[i] = true;
            int cnt = 1;
            int j = dec(i);
            while(!visited[j] && a[j] == 1) {
                visited[j] = true;
                cnt++;
                j = dec(j);
            }
            if (j == i) {
                ans = -1;
                break;
            }
            j = inc(i);
            while(!visited[j] && a[j] == 1) {
                visited[j] = true;
                cnt++;
                j = inc(j);
            }
            chmax(ans, cnt);
        }
        cout << ans << '\n';
    }
}