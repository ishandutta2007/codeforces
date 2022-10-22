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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        VI a(n), b(n);
        rep(i, n) cin >> a[i];
        for(int i = n % 2 == 0 ? 0 : 3; i < n; i += 2) {
            b[i] = -a[i + 1];
            b[i + 1] = a[i];
        }
        if (n % 2) {
            int i, j, k;
            if (a[0] + a[1] != 0) i = 0, j = 1, k = 2;
            else if (a[1] + a[2] != 0) i = 1, j = 2, k = 0;
            else i = 2, j = 0, k = 1;
            b[i] = -a[k];
            b[j] = -a[k];
            b[k] = a[i] + a[j];
        }
        rep(i, n) cout << b[i] << " \n"[i + 1 == n];
    }
}