#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
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
        VL a(n);
        rep(i, n) cin >> a[i];
        VL s(n + 1);
        rep(i, n) {
            s[i + 1] = s[i] + (i % 2 == 0 ? a[i] : -a[i]);
        }
        if (s[n] == 0) {
            bool ok = true;
            for(int i = 0; i <= n; i += 2) {
                if (s[i] > 0) ok = false;
            }
            for(int i = 1; i <= n; i += 2) {
                if (s[i] < 0) ok = false;
            }
            cout << (ok ? "YES\n" : "NO\n");
        } else {
            int broken = n;
            rep(i, n + 1) {
                if (i % 2 == 0 && s[i] > 0 || i % 2 == 1 && s[i] < 0) {
                    broken = i;
                    break;
                }
            }
            bool ok = false;
            if (broken < n) {
                swap(a[broken - 1], a[broken]);
                ll now = 0;
                bool success = true;
                rep(i, n) {
                    if (i % 2 == 0) {
                        now += a[i];
                        if (now < 0) {
                            success = false;
                            break;
                        }
                    } else {
                        now -= a[i];
                        if (now > 0) {
                            success = false;
                            break;
                        }
                    }
                }
                if (now != 0) success = false;
                if (success) ok = true;
                swap(a[broken - 1], a[broken]);
            }
            if (!ok) {
                for(int p = broken - 2; p >= 0; --p) {
                    bool bb = false;
                    if (p % 2 == 0 && s[n] - 2 * a[p] + 2 * a[p + 1] == 0) {
                        if (s[p] + a[p+1] >= 0 && s[p] + a[p+1] - a[p] <= 0) bb = true;
                    } else if (p % 2 == 1 && s[n] + 2 * a[p] - 2 * a[p + 1] == 0) {
                        if (s[p] - a[p+1] <= 0 && s[p] - a[p+1] + a[p] >= 0) bb = true;
                    }
                    if (bb) {
                        swap(a[p], a[p + 1]);
                        ll now = 0;
                        bool success = true;
                        rep(i, n) {
                            if (i % 2 == 0) {
                                now += a[i];
                                if (now < 0) {
                                    success = false;
                                    break;
                                }
                            } else {
                                now -= a[i];
                                if (now > 0) {
                                    success = false;
                                    break;
                                }
                            }
                        }
                        if (now != 0) success = false;
                        if (success) ok = true;
                        break;
                    }
                }
            }
            cout << (ok ? "YES\n" : "NO\n");
        }
    }
}