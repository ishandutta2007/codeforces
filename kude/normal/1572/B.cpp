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
        int n;
        cin >> n;
        VI a(n);
        rep(i, n) cin >> a[i];
        VI ans;
        auto op = [&](int i) {
            assert(i + 3 <= n);
            int x = 0;
            rep(k, 3) x ^= a[i + k];
            rep(k, 3) a[i + k] = x;
            ans.push_back(i);
        };
        if (accumulate(all(a), 0) % 2) {
            cout << "NO\n";
            continue;
        }
        int i = 0;
        bool ok = true;
        while(i < n) {
            while(i < n && a[i] == 0) i++;
            if (i == n) break;
            if (i) {
                int j = i + 1;
                while(a[j] == 0) j++;
                int t = j;
                while(t > i) t -= 2;
                for(int p = t; p <= j - 2; p += 2) op(p);
                for(int p = j - 4; p >= t; p -= 2) op(p);
                i = j;
            } else {
                int i_end = i + 1;
                while(i_end < n && a[i_end] == 1) i_end++;
                if (i_end == n) {
                    ok = false;
                    break;
                }
                if (i_end % 2 == 0) {
                    for(int p = i_end - 2; p >= 0; p -= 2) op(p);
                    i = i_end;
                    continue;
                }
                int j = i_end, j_end = -1;
                while(true) {
                    while(a[j] == 0) j++;
                    if ((j - i_end) % 2) {
                        for(int p = j - 2; p >= 0; p -= 2) op(p);
                        break;
                    }
                    j_end = j + 1;
                    while(j_end < n && a[j_end]) j_end++;
                    if ((j_end - j) % 2 == 0) {
                        j = j_end;
                        continue;
                    }
                    if (j_end == n) {
                        ok = false;
                        break;
                    }
                    for(int p = j_end - 2; p >= 0; p -= 2) op(p);
                    break;
                }
                if (!ok) break;
            }
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        int sz = ans.size();
        cout << sz << '\n';
        rep(i, sz) cout << ans[i] + 1 << " \n"[i + 1 == sz];
    }
}