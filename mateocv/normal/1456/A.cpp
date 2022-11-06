#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll INF=(1ll<<60);

ll cf[100005];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,p,k; cin>>n>>p>>k; p--;
		string s; cin>>s;
		ll x,y; cin>>x>>y;
		ll res=INF;
		fore(i,0,n)cf[i]=0;
		for(ll i=n-1;i>=0;i--){
			cf[i]=(s[i]=='0'?x:0);
			if(i+k<n)cf[i]+=cf[i+k];
		}
		fore(i,p,n)res=min(res,cf[i]+(i-p)*y);
		cout<<res<<"\n";
	}
	
	return 0;
}