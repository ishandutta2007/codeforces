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
    int n; cin>>n;
    int a[n];
    bool pass = true;
    for(int i=0;i<n;i++)
        cin>>a[i], pass &= (a[i] == 0);
    if(pass) {
        cout<<"0\n";
        return;
    }
    pass = true;
    int ct = 0;
    ct += (a[0] != 0);
    for(int i=1;i<n;i++) {
        if(a[i] != 0 && a[i-1] == 0)
            ct++;
    }
    pass = (ct == 1);
    if(pass) {
        cout<<"1\n";
        return;
    }
    cout<<"2\n";
    return;
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