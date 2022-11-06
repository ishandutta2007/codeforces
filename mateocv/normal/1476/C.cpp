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

ll n;
const int MAXN=100005;

ll a[MAXN],b[MAXN],c[MAXN];

ll dp[MAXN];

ll f(ll x){
	ll &res=dp[x];
	if(res>=0)return res;
	if(x==0)return res=0;
	res=abs(a[x]-b[x])+2;
	if(x>1&&b[x]!=a[x])res=max(res,min(abs(a[x]-1)+abs(b[x]-c[x-1]),abs(a[x]-c[x-1])+abs(b[x]-1))+2+f(x-1));
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n)cin>>c[i];
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		fore(i,0,n)dp[i]=-1;
		ll res=0;
		/*
		fore(i,0,n)cout<<a[i]<<" "; cout<<"\n";
		fore(i,0,n)cout<<b[i]<<" "; cout<<"\n";
		fore(i,0,n)cout<<c[i]<<" "; cout<<"\n";
		fore(i,0,n)cout<<f(i)<<" "; cout<<"\n";
		*/
		fore(i,1,n)res=max(res,f(i)+c[i]-1);
		cout<<res<<"\n";
	}
	
	return 0;
}