#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

void solve(){
    int n,m; cin>>n>>m;
    vector<pii> a,b;
    for(int i=0;i<n;i++) {
        int l; cin>>l;
        int x = 1;
        while(l%m == 0) {
            x *= m;
            l /= m;
        }
        if(!a.empty() && a.back().first == l) {
            a.back().second += x;
        }
        else {
            a.push_back({l,x});
        }
    }
    cin>>n;
    for(int i=0;i<n;i++) {
        int l; cin>>l;
        int x = 1;
        while(l%m == 0) {
            x *= m;
            l /= m;
        }
        if(!b.empty() && b.back().first == l) {
            b.back().second += x;
        }
        else {
            b.push_back({l,x});
        }
//        cout<<i<<' '<<b.back().second<<endl;
    }
//    for(auto it: a) {
//        cout<<it.first<<' '<<it.second<<endl;
//    }
//    cout<<"NX\n";
//    for(auto it: b) {
//        cout<<it.first<<' '<<it.second<<endl;
//    }
    if(a == b) {
        cout<<"Yes\n";
    }
    else {
        cout<<"No\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin>>T; // Comment this out if it is a single testcase
    while(T--)
        solve();
    return 0;
}