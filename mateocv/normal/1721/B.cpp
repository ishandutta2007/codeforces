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
		ll n,m,x,y,d; cin>>n>>m>>x>>y>>d;
		ll res=-1;
		if(x-d>1&&y+d<m)res=(n+m-2);
		if(x+d<n&&y-d>1)res=(n+m-2);
		cout<<res<<"\n";
	}
	
	return 0;
}