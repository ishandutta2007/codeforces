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
    int pow10[10];
    pow10[0] = 1;
    rep(i, 9) pow10[i+1] = pow10[i] * 10;
    cin >> tt;
    while(tt--) {
        int a, b, c;
        cin >> a >> b >> c;
        int g = pow10[c-1];
        int x = pow10[a-c];
        int y = pow10[b-c];
        while(gcd(x,y) != 1) y++;
        cout << g * x << ' ' << g * y << '\n';
    }
}