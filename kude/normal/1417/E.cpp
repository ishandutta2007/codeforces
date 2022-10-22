#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
    int n;
    cin >> n;
    VVI a(1, VI(n));
    rep(i, n) cin >> a[0][i];
    int x = 0;
    ll tot = 0;
    for(int k = 30; k >= 0; k--) {
        ll i10 = 0, i01 = 0;
        int mask = 1 << k;
        for(auto &s: a) {
            int cnt0 = 0, cnt1 = 0;
            for(int ai: s) {
                if (ai & mask) {
                    i01 += cnt0;
                    cnt1++;
                } else {
                    i10 += cnt1;
                    cnt0++;
                }
            }
        }
        if (i10 > i01) {
            x |= mask;
            tot += i01;
        } else {
            tot += i10;
        }
        VVI na;
        for(auto &s: a) {
            VI a0, a1;
            for(int ai: s) {
                if (ai & mask) a1.push_back(ai);
                else a0.push_back(ai);
            }
            if(!a0.empty())na.push_back(a0);
            if(!a1.empty())na.push_back(a1);
        }
        a = move(na);
    }
    cout << tot << ' ' << x << endl;
}