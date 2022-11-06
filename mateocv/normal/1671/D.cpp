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
		ll n,x; cin>>n>>x;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		ll d=0;
		fore(i,0,n-1)d+=abs(a[i]-a[i+1]);
		ll mini1=min(abs(a[0]-1),abs(a.back()-1));
		fore(i,0,n-1)mini1=min(mini1,-abs(a[i]-a[i+1])+abs(a[i]-1)+abs(1-a[i+1]));
		ll minix=min(abs(a[0]-x),abs(a.back()-x));
		fore(i,0,n-1)minix=min(minix,-abs(a[i]-a[i+1])+abs(a[i]-x)+abs(x-a[i+1]));
		ll mini2=x-1+min(abs(a[0]-x),abs(a.back()-1));
		fore(i,0,n-1)mini2=min(mini2,-abs(a[i]-a[i+1])+abs(a[i]-1)+abs(x-a[i+1])+x-1);
		ll mini3=x-1+min(abs(a[0]-1),abs(a.back()-x));
		fore(i,0,n-1)mini3=min(mini3,-abs(a[i]-a[i+1])+abs(a[i]-x)+abs(1-a[i+1])+x-1);
		if(x==1)cout<<d+mini1<<"\n";
		else cout<<d+min({mini1+minix,mini2,mini3})<<"\n";
	}
	
	return 0;
}