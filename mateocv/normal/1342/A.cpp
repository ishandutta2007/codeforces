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
		ll x,y; cin>>x>>y;
		ll a,b; cin>>a>>b;
		ll res=(abs(x)+abs(y))*a;
		if((x>=0&&y>=0)||(x<=0&&y<=0)){
			res=min(res,min(abs(x),abs(y))*b+a*(max(abs(x),abs(y))-min(abs(x),abs(y))));
		}
		cout<<res<<"\n";
	}
	return 0;
}