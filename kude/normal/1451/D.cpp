#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

ll dist(ll x, ll y) {
    return x * x + y * y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        ll d, k;
        cin >> d >> k;
        ll x = 0, y = 0;
        while(dist(x + k, y + k) <= d * d) x += k, y += k;
        int cnt = 0;
        while(dist(x + k, y) <= d * d) x += k, cnt++;
        if (cnt % 2 == 0) cout << "Utkarsh\n";
        else cout << "Ashish\n";
    }
}