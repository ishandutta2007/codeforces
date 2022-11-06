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

ll n,k,mm;

ll cante[200005][18];

ll ne[200005][18];

ll INF=2e9;

ll dp[(1ll<<17)];

ll f(ll x){
	ll &res=dp[x];
	if(res>=0)return res;
	if(x==0)return res=0;
	res=INF;
	fore(i,0,k){
		if((1ll<<i)&x){
			ll ff=f(x^(1ll<<i));
			if(ff>=n)continue;
			ll nn=ne[ff][i];
			if(nn!=-1){
				res=min(res,nn+mm);
			}
		}
	}
	return res;
}

bool can(ll m){
	mm=m;
	for(ll i=n-1;i>=0;i--){
		fore(j,0,k){
			if(i==n-1){
				ne[i][j]=-1;
			}else{
				ne[i][j]=ne[i+1][j];
			}
			if(cante[i][j]>=m)ne[i][j]=i;
		}
	}
	mset(dp,-1);
	if(f((1ll<<k)-1)<INF)return 1;
	return 0;
}

int main(){FIN;
	cin>>n>>k;
	string s; cin>>s;
	for(ll i=n-1;i>=0;i--){
		fore(j,0,k){
			if(s[i]=='?'||s[i]=='a'+j){
				cante[i][j]=1;
				if(i+1<n)cante[i][j]+=cante[i+1][j];
			}
		}
	}
	ll l=0,r=n;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))l=m+1;
		else r=m-1;
	}
	cout<<r<<"\n";
	
	return 0;
}