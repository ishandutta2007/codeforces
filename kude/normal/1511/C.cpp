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
    int pos[99];
    rep(i, 99) pos[i] = -1;
    int n, q;
    cin >> n >> q;
    rep(i, n) {
        int a;
        cin >> a;
        if (pos[a] == -1) pos[a] = i;
    }
    rep(_, q) {
        int t;
        cin >> t;
        int p = pos[t];
        cout << p + 1 << " \n"[_ + 1 == q];
        rep(i, 99) if (pos[i] != -1 && pos[i] < p) pos[i]++;
        pos[t] = 0;
    }
}