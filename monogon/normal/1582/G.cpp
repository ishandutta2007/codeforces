
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
    int n;
    cin >> n;
    vi a(n + 1);
    string s;
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    cin >> s;
    s = "$" + s;
    rep(i, 1, n + 1) {
        if(a[i] == 1) s[i] = '*';
    }
    const int A = 1e6 + 5;
    vi prime(A);
    prime[1] = 1;
    rep(i, 2, A) {
        if(prime[i] == 0) {
            for(int j = i; j < A; j += i) {
                prime[j] = i;
            }
        }
    }
    vector<map<int, int>> st;
    ll ans = 0;
    vi p(A), cnt(A);
    rep(i, 1, n + 1) {
        int si = 0;
        ll x = a[i];
        while(x != 1) {
            p[si] = prime[x];
            cnt[si] = 0;
            while(x % p[si] == 0) {
                x /= p[si];
                cnt[si]++;
            }
            si++;
        }
        if(s[i] == '*') {
            map<int, int> ma;
            rep(j, 0, si) ma[p[j]] = cnt[j];
            st.push_back(ma);
        }else {
            while(!st.empty()) {
                bool ok = true;
                rep(j, 0, si) {
                    if(st.back().count(p[j]) == 0 || st.back()[p[j]] < cnt[j]) {
                        ok = false;
                        break;
                    }
                }
                if(ok) {
                    rep(j, 0, si) {
                        st.back()[p[j]] -= cnt[j];
                    }
                    break;
                }else {
                    if(st.size() >= 2) {
                        map<int, int> &A = st.back(), &B = st[sz(st) - 2];
                        if(sz(A) > sz(B)) {
                            for(auto &pa : B) {
                                A[pa.first] += pa.second;
                            }
                            A.swap(B);
                        }else {
                            for(auto &pa : A) {
                                B[pa.first] += pa.second;
                            }
                        }
                    }
                    st.pop_back();
                }
            }
        }
        ans += sz(st);
    }
    cout << ans << '\n';
}