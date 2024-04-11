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

ll n,a,r,m; 

ll h[100005];

ll solve(ll mid){
	ll x=0,y=0;
	fore(i,0,n){
		if(h[i]>=mid){
			x+=h[i]-mid;
		}else{
			y+=mid-h[i];
		}
	}
	return min(x*r+y*a,(max(x,y)-min(x,y))*(x>y?r:a)+(min(x,y))*m);
}

int main(){FIN;
	cin>>n>>a>>r>>m;
	fore(i,0,n)cin>>h[i];
	ll el=0,er=1e9+10;
/*	fore(i,0,11){
		cout<<solve(i)<<"\n";
	}*/
	while(3<=er-el) {
		ll mid = (el+er)/2;
		if (solve(mid)>solve(mid+1)) el=mid;
		else er=mid+1;
	}
	//cout<<el<<" "<<er<<"\n";
	ll res=solve(1);
	fore(i,el,er+1){
		res=min(solve(i),res);
	}
	cout<<res;
	return 0;
}