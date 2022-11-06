#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200010
#define MOD 998244353
#define INF (ll)1e+18
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
struct Setup_io {
	Setup_io() {
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cout << fixed << setprecision(15);
	}
} setup_io;


int main() {
    vector<ll>a[2];
    int t;
    int c[N];
	int n,k,sz;
    ll x,y;

    cin >> t;
    rep(tt,t){
        a[0].clear();
        a[1].clear();

        cin>>n;
        rep(i,n)cin >> c[i];
        y = 0;
        rep(i,n){
            cin>>x;
            y += x;
            a[c[i]].pb(x);
        }
        sort(all(a[0]));
        sort(all(a[1]));
        if(a[0].size()==a[1].size()){
            sz=a[0].size();
            rep(i,sz)y+=a[0][i];
            sz=a[1].size();
            rep(i,sz)y+=a[1][i]; 
            y-=min(a[0][0],a[1][0]);     
        }
        else{
            k=min((int)a[0].size(),(int)a[1].size());
            sz=a[0].size();
            rep2(i,sz-k,sz-1)y+=a[0][i];
            sz=a[1].size();
            rep2(i,sz-k,sz-1)y+=a[1][i]; 
        }
        cout << y << endl;
    }
	return 0;
}