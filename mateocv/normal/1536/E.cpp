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

const int MOD=1000000007;

ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<string> s(n);
		fore(i,0,n)cin>>s[i];
		ll c[2]={0,0};
		fore(i,0,n){
			fore(j,0,m){
				if(s[i][j]=='#')c[1]++;
				else c[0]++;
			}
		}
		ll res=fpow(2,c[1]);
		if(c[0]==0)res=(res+MOD-1)%MOD;
		cout<<res<<"\n";
	}
	
	return 0;
}