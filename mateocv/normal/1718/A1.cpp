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

bool val[5050][5050];

ll dp[5050];

ll n;

ll f(ll x){
	ll &res=dp[x];
	if(res>=0)return res;
	if(x==n)return res=0;
	res=f(x+1)+1;
	fore(i,x+1,n+1)if(val[x][i])res=min(res,f(i)+i-x-1);
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,SZ(a)+1){
			fore(j,0,SZ(a)+1){
				val[i][j]=0;
			}
		}
		fore(i,0,SZ(a)){
			ll x=0;
			fore(j,i,SZ(a)){
				x^=a[j];
				if(x==0)val[i][j+1]=1;
			}
		}
		fore(i,0,SZ(a)+2)dp[i]=-1;
		cout<<f(0)<<"\n";
	}
	
	return 0;
}