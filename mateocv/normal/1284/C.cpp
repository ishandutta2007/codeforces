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

ll f[300005];

int main(){FIN;
	ll n,m; cin>>n>>m;
	f[0]=1;
	fore(i,0,n)f[i+1]=((i+1)*f[i])%m;
	ll res=0;
	fore(i,1,n+1){
		ll t=(n+1-i)*(n+1-i); t%=m;
		t*=f[i]; t%=m;
		t*=f[n-i]; t%=m;
		res+=t;
		if(res>m)res-=m;
	}
	cout<<res;
	return 0;
}