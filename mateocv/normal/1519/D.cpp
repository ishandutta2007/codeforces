#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

vector<ll> a,b,sumpr;

int main(){FIN;
	ll n; cin>>n;
	a.resize(n);
	b.resize(n);
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)cin>>b[i];
	sumpr.pb(0);
	fore(i,0,n){
		sumpr.pb(a[i]*b[i]+sumpr.back());
	}
	ll res=sumpr.back();
	fore(i,0,n){
		ll va=sumpr.back();
		fore(j,1,n){
			if(i-j>=0&&i+j<n){
				va-=a[i-j]*b[i-j];
				va-=a[i+j]*b[i+j];
				va+=a[i-j]*b[i+j];
				va+=a[i+j]*b[i-j];
			}
			res=max(res,va);
		}
	}
	fore(i,0,n-1){
		ll va=sumpr.back();
		fore(j,0,n){
			if(i-j>=0&&i+1+j<n){
				va-=a[i-j]*b[i-j];
				va-=a[i+j+1]*b[i+j+1];
				va+=a[i-j]*b[i+j+1];
				va+=a[i+j+1]*b[i-j];
			}
			res=max(res,va);
		}
	}
	cout<<res<<"\n";
	return 0;
}