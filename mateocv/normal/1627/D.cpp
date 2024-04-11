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

const int MAXN=1000006;

bool vis[MAXN];

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n){
		ll x; cin>>x;
		vis[x]=1;
	}
	ll res=-n;
	fore(i,1,MAXN){
		ll g=0;
		for(ll j=i;j<MAXN;j+=i){
			if(vis[j])g=__gcd(g,j);
		}
		if(g==i)res++;
	}
	cout<<res<<"\n";
	
	return 0;
}