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

const int MAXN=300005;

ll p[MAXN][19];

ll a[MAXN],c[MAXN];

ll find(ll v){
	for(ll k=18;k>=0;k--){
		if(p[v][k]!=-1&&a[p[v][k]]){
			v=p[v][k];
		}
	}
	if(a[v])return v;
	return -1;
}

pair<ll,ll> solve(ll v, ll w){
	pair<ll,ll> res={0,0};
	while(1){
		auto pp=find(v);
		if(pp==-1)break;
		ll mini=min(w,a[pp]);
		w-=mini;
		a[pp]-=mini;
		res.fst+=mini;
		res.snd+=mini*c[pp];
		if(w==0)break;
	}
	return res;
}

int main(){FIN;
	ll q; cin>>q>>a[0]>>c[0];
	fore(j,0,19)p[0][j]=-1;
	fore(i,1,q+1){
		ll ty; cin>>ty;
		if(ty==1){
			ll pa; cin>>pa>>a[i]>>c[i];
			p[i][0]=pa;
			fore(j,1,19){
				if(p[i][j-1]!=-1)p[i][j]=p[p[i][j-1]][j-1];
				else p[i][j]=-1;
			}
		}else{
			ll v,w; cin>>v>>w;
			auto res=solve(v,w);
			cout<<res.fst<<" "<<res.snd<<endl;
		}
	}
	
	return 0;
}