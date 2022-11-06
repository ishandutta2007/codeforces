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

bool val(ll x, ll y, ll n, ll m){
	return 0<=x&&x<n&&0<=y&&y<m;
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	char c[n][m];
	fore(i,0,n){
		fore(j,0,m){
			cin>>c[i][j];
		}
	}
	ll res=0;
	pair<ll,ll> pos={0,0};
	while(1){
		if(c[pos.fst][pos.snd]=='*')res++;
		if(pos==pair<ll,ll>({n-1,m-1}))break;
		if(!val(pos.fst+1,pos.snd,n,m))pos.snd++;
		else if(!val(pos.fst,pos.snd+1,n,m))pos.fst++;
		else{
			if(c[pos.fst+1][pos.snd]=='*'&&c[pos.fst][pos.snd+1]=='.')pos.fst++;
			else pos.snd++;
		}
	}
	cout<<res<<"\n";
	
	return 0;
}