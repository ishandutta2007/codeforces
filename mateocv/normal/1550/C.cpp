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

vector<ll> a;

ll solve(ll l, ll r){
	if(r-l<=2)return 1;
	fore(i,l,r){
		fore(j,i+1,r){
			fore(k,j+1,r){
				if((a[i]<=a[j]&&a[j]<=a[k])||(a[i]>=a[j]&&a[j]>=a[k])){
					return 0;
				}
			}
		}
	}
	return 1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		a.clear();
		a.resize(n);
		fore(i,0,n)cin>>a[i];
		ll res=0;
		fore(i,0,n){
			fore(j,1,7){
				if(i+j<=n)res+=solve(i,i+j);
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}