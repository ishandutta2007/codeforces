#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200010
#define MOD 998244353
#define INF (ll)1e+18
#define ll long long
#define rep(i, n) for(ll i = 0; i < n; ++i)
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
    ll t,n,k;
    ll a[N];
    ll x,y;
    bool v;

    cin >> t;
    rep(tt,t){
        v = true;
        cin >> n >> k;
        rep(i,k)cin >> a[i];
        x=a[0];
        if(k == 1){
            cout << "YES" << endl;
            continue;
        }
        rep(i,k-1){
            a[i]=a[i+1]-a[i];
            if(i>0){
                if(a[i-1]>a[i])v = false;
            }
        }
        y=a[0]*(n-k+1);
        if(x>y)v = false;
        if(v)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
	return 0;
}