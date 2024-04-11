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
	ll n,x; cin>>n>>x;
	ll a[2*n];
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)a[i+n]=a[i];
	ll b[2*n];
	fore(i,0,2*n)b[i]=(a[i]+1)*a[i]/2;
	ll sumpa[2*n+1],sumpb[2*n+1];
	sumpa[0]=0;
	sumpb[0]=0;
	fore(i,0,2*n)sumpa[i+1]=sumpa[i]+a[i];
	fore(i,0,2*n)sumpb[i+1]=sumpb[i]+b[i];
	ll l=0,r=0;
	ll res=0;
	while(r<2*n){
		//cout<<l<<" "<<r<<endl;
		while(sumpa[r]-sumpa[l]<x){
			r++;
			if(r==2*n)break;
		}
		while(sumpa[r]-sumpa[l+1]>=x)l++;
		ll c=sumpa[r]-sumpa[l]-x;
		res=max(res,sumpb[r]-sumpb[l]-c*(c+1)/2);
		l++;
	}
	cout<<res<<"\n";
	return 0;
}