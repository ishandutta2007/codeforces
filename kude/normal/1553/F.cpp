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

constexpr int SQ = 450;
int a[200000];
ll p[200000];
constexpr int MX = 300100;
ll event1[MX];
VI event2[MX];
bool exists[MX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    rep(i, n) cin >> a[i];
    for(int b = 0; b < n; b += SQ) {
        int nb = min(b + SQ, n);
        for(int i = b; i < nb; i++) for(int j = i + 1; j < nb; j++) {
            p[j] += a[i] % a[j] + a[j] % a[i];
        }
        // mod side
        ll sm = 0;
        rep(i, b) sm += a[i];
        for(int i = b; i < nb; i++) p[i] += sm + (ll)b * a[i];
        {
            ll now = 0;
            VI ord;
            for(int i = b; i < nb; i++) ord.push_back(i);
            sort(all(ord), [&](int i, int j) {return a[i] < a[j];});
            int idx = 0;
            for(int i: ord) {
                int x = a[i];
                while(idx <= x) now += event1[idx++];
                p[i] -= now;
            }
        }
        {
            for(int i = b; i < nb; i++) {
                int x = a[i];
                for(int y = x; y < MX; y += x) event2[y].push_back(i);
            }
            int rest = b;
            rep(i, MX) {
                for(int j: event2[i]) p[j] -= (ll)rest * a[j];
                rest -= exists[i];
            }
            rep(i, MX) event2[i].clear();
        }

        for(int i = b; i < nb; i++) {
            int x = a[i];
            for(int y = x; y < MX; y += x) event1[y] += x;
            exists[x] = true;
        }
    }
    ll now = 0;
    rep(i, n) {
        now += p[i];
        p[i] = now;
    }
    rep(i, n) cout << p[i] << " \n"[i + 1 == n];
}