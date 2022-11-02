#include <bits/stdc++.h>
using namespace std;

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
    int n,z; cin>>n>>z;
    int maxi = 0;
    for(int i=0;i<n;i++) {
        int a; cin>>a;
        maxi = max(maxi,(a | z));
    }
    cout<<maxi<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin>>T; // Comment this out if it is a single testcase
    while(T--)
        solve();
    return 0;
}