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
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll b[n];
		mset(b,0);
		fore(i,0,n){
			if(i-1>=0&&i+1<n){
				b[i]=(a[i-1]<a[i])&&(a[i]>a[i+1]);
			}
		}
		//fore(i,0,n)cout<<b[i]<<" "; cout<<"\n";
		ll sump[n+1];
		sump[0]=0;
		fore(i,0,n)sump[i+1]=sump[i]+b[i];
		//fore(i,0,n+1)cout<<sump[i]<<" "; cout<<"\n";
		ll res=0,l=0;
		fore(i,0,n-k+1){
			//cout<<i+k-1<<" "<<sump[i+k-1]<<"\n";
			//cout<<i+1<<" "<<sump[i+1]<<"\n";
			if(sump[i+k-1]-sump[i+1]>res){
				res=sump[i+k-1]-sump[i+1];
				l=i;
			}
		}
		cout<<res+1<<" "<<l+1<<"\n";
	}
	
	return 0;
}