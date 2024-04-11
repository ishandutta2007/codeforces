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

string a,b;

ll n;

ll dp[100005][3];

ll f(ll x, ll y){
	ll &res=dp[x][y];
	if(res>=0)return res;
	if(x==n)return res=(y==0);
	res=0;
	if(y==2){
		if(a[x]==b[x]){
			res=max(res,f(x+1,a[x]-'0'));
			res=max(res,f(x+1,2)+((a[x]-'0')^1));
		}else{
			res=max(res,f(x+1,2)+2);
		}
	}else{
		if(a[x]==b[x]){
			if(a[x]==a[x-1])res=max(res,f(x+1,2)+((a[x]-'0')^1));
			else res=max(res,f(x+1,2)+2);
		}else{
			res=max(res,f(x+1,2)+2);
		}
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>a>>b;
		fore(i,0,n+1){
			fore(j,0,3)dp[i][j]=-1;
		}
		cout<<f(0,2)<<"\n";
	}
	
	return 0;
}