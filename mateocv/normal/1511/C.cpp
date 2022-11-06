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
	ll n,t; cin>>n>>t;
	ll c[50];
	mset(c,-1);
	fore(i,0,n){
		ll x; cin>>x; x--;
		if(c[x]==-1)c[x]=i;
	}
	while(t--){
		ll x; cin>>x; x--;
		ll res=c[x];
		cout<<res+1<<" ";
		fore(i,0,50){
			if(c[i]<res)c[i]++;
		}
		c[x]=0;
	}
	
	return 0;
}