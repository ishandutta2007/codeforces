#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n; cin>>n;
	ll a[n],b[n];
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)cin>>b[i];
	ll u[n+1];
	fore(i,0,n){
		if(a[i]>0)u[a[i]]=0;
		if(b[i]>0)u[b[i]]=i+1;
	}
	ll val[n+1];
	ll res=0;
	fore(i,1,n+1){
		val[i]=u[i]-i+1;
		res=max(res,val[i]);
	}
	//fore(i,1,n+1)cout<<val[i]<<" ";
	ll tot=0;
	if(res==val[1]&&val[1]>0){
		tot++;
		fore(i,u[1],n){
			if(b[i]==i-u[1]+2){
				tot++;
			}
		}
		fore(i,n-val[1]+2,n+1){
			if(u[i]<=i-n+val[1]-2)tot++;
		}
		if(tot==n){
			cout<<val[1]-1;
		}else{
			cout<<res+n;
		}
	}else{
		cout<<res+n;
	}
	
	return 0;
}