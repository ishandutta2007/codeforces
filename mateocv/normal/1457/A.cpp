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
		ll n,m,r,c; cin>>n>>m>>r>>c;
		ll res=0;
		res=max(res,abs(1-r)+abs(1-c));
		res=max(res,abs(n-r)+abs(1-c));
		res=max(res,abs(1-r)+abs(m-c));
		res=max(res,abs(n-r)+abs(m-c));
		cout<<res<<"\n";
	}
	
	return 0;
}