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
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll res[2]={0,0};
		fore(i,0,n)res[0]+=(a[i]+x-1)/x,res[1]+=a[i];
		res[1]=(res[1]+x-1)/x;
		cout<<res[1]<<" "<<res[0]<<"\n";
	}
	
	return 0;
}