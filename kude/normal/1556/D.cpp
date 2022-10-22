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

int q_and(int i, int j) {
    cout << "and " << i + 1 << ' ' << j + 1 << endl;
    int x;
    cin >> x;
    return x;
}
int q_or(int i, int j) {
    cout << "or " << i + 1 << ' ' << j + 1 << endl;
    int x;
    cin >> x;
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    VI a(n);
    bool determined[30] = {};
    VI a_and(n);
    VI a_or(n);
    for(int i = 1; i < n; i++) {
        a_and[i] = q_and(0, i);
        a_or[i] = q_or(0, i);
        rep(d, 30) if (a_and[i] >> d & 1) {
            a[0] |= 1 << d;
            determined[d] = true;
        }
        rep(d, 30) if ((a_or[i] >> d & 1) == 0) {
            determined[d] = true;
        }
    }
    int x = q_and(1, 2);
    rep(d, 30) if (!determined[d]) {
        a[0] |= ((x >> d & 1) ^ 1) << d;
    }
    for(int i = 1; i < n; i++) {
        a[i] = a_and[i];
        rep(d, 30) if ((a_and[i] >> d & 1) == 0 && (a_or[i] >> d & 1) == 1) {
            a[i] |= ((a[0] >> d & 1) ^ 1) << d;
        }
    }
    sort(all(a));
    cout << "finish " << a[k - 1] << endl;
}