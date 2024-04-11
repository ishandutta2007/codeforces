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
 
int main(){FIN;
	ll n,k; cin>>n>>k;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	ll l=0,r=1000000005;
	while(l<=r){
		ll m=(l+r)/2;
		ll tot[2];
		mset(tot,0);
		ll va=0;
		fore(i,0,n){
			if(va==0){
				if(a[i]<=m)tot[va]++,va=1;
			}else{
				tot[va]++,va=0;
			}
		}
		if(tot[0]+tot[1]>=k){
			r=m-1;
			continue;
		}
		mset(tot,0);
		va=1;
		fore(i,0,n){
			if(va==0){
				if(a[i]<=m)tot[va]++,va=1;
			}else{
				tot[va]++,va=0;
			}
		}
		if(tot[0]+tot[1]>=k){
			r=m-1;
			continue;
		}
		l=m+1;
	}
	cout<<l;
	
	return 0;
}