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

string s;

ll k; 

ll dp[55][55];

ll spos(ll x){
	fore(i,0,x)if(s[i]=='*')return 0;
	return 1;
}

ll fipos(ll x){
	fore(i,x+1,SZ(s))if(s[i]=='*')return 0;
	return 1;
}

ll f(ll x, ll y){
	ll &res=dp[x][y];
	if(res>=0)return res;
	if(x==SZ(s))return res=0;
	if(s[x]=='.')res=f(x+1,y);
	if(s[x]=='*'){
		if(spos(x))res=f(x+1,x)+1;
		else{
			if(x-y>k)res=1e9;
			else{
				if(fipos(x))res=1;
				else res=min(f(x+1,y),f(x+1,x)+1);
			}
		}
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n>>k;
		cin>>s;
		mset(dp,-1);
		cout<<f(0,0)<<"\n";
	}
	
	return 0;
}