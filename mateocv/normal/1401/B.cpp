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
		ll a[2],b[2],c[2];
		fore(k,0,2)cin>>a[k]>>b[k]>>c[k];
		ll res=0;
		res+=2*min(c[0],b[1]);
		c[0]-=res/2;
		b[1]-=res/2;
		ll sum=a[0]+b[0]+c[0];
		//cout<<sum<<"\n";
		res-=2*(max(c[1]+b[0]-sum,0ll));
		cout<<res<<"\n";
	}
	
	return 0;
}