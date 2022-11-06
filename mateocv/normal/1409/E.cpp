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
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		ll x[n],y;
		fore(i,0,n)cin>>x[i];
		fore(i,0,n)cin>>y;
		sort(x,x+n);
		ll d[n];
		ll r=0;
		fore(i,0,n){
			if(r>=n){
				d[i]=n-i;
			}else{
				while(x[r]-x[i]<=k){
					r++;
					if(r==n)break;
				}
				if(r>=n)d[i]=n-i;
				else{
					d[i]=r-i;
				}
			}
		}
		//fore(i,0,n)cout<<d[i]<<" "; cout<<"\n";
		ll suf[n+1];
		suf[n]=0;
		suf[n-1]=d[n-1];
		for(int i=n-2;i>=0;i--){
			suf[i]=max(suf[i+1],d[i]);
		}
		ll res=0;
		fore(i,0,n){
			res=max(res,d[i]+suf[i+d[i]]);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}