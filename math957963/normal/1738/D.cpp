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

int n;
vector<int>e[N];
vector<int>a;

void dfs(int k){
    int sz=e[k].size();
    rep(i,sz){
        if(e[e[k][i]].size()==0)a.pb(e[k][i]);
    }
    rep(i,sz){
        if(e[e[k][i]].size()>0){
            a.pb(e[k][i]);
            dfs(e[k][i]);
        }
    }
    return;
}


int main() {
    int t,x,y;

    cin >> t;
    rep(tt,t){
        a.clear();
        y = 0;
        cin >> n;
        rep(i,n){
            cin >> x;
            if((i+1)<x)y=i+1;
            e[x].pb(i+1);
        }
        if(e[0].size()>0)dfs(0);
        else dfs(n+1);

        cout << y <<endl;
        rep(i,n){
            cout<< a[i];
            if(i<(n-1))cout << " ";
            else cout << endl;
        }
        rep(i,n+2)e[i].clear();
    }
	return 0;
}