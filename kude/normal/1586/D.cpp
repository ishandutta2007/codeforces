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

int query(const VI& a) {
    int n = a.size();
    cout << "? ";
    rep(i, n) cout << a[i] + 1 << " \n"[i + 1 == n];
    cout << flush;
    int res;
    cin >> res;
    return res - 1;
}

void answer(const VI& a) {
    int n = a.size();
    cout << "! ";
    rep(i, n) cout << a[i] + 1 << " \n"[i + 1 == n];
    cout << flush;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int last = 0;
    for(; last < n - 1; last++) {
        VI a(n);
        a[n - 1] = n - 1 - last;
        if (query(a) >= 0) break;
    }
    VI ans(n);
    ans[n - 1] = last;
    rep(i, n) if (i != last) {
        VI a;
        if (i < last) {
            a = VI(n, n - 1);
            a[n - 1] = n - 1 - (last - i);
        } else {
            a = VI(n);
            a[n - 1] = i - last;
        }
        int idx = query(a);
        assert(idx >= 0);
        ans[idx] = i;
    }
    answer(ans);
}