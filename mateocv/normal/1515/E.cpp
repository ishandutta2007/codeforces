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

ll MOD;

const int MAXN=404;

/*----------------FPOW----------------*/
ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

ll add(ll x, ll y){
	x+=y;
	if(x>=MOD)x-=MOD;
	return x;
}

ll sump[MAXN][MAXN];
ll sump2[MAXN][MAXN];

ll cant[MAXN];

ll comb[MAXN][MAXN];

ll dp[MAXN][MAXN];

ll f(ll x, ll y){
	ll &res=dp[x][y];
	if(res>=0)return res;
	if(x==0)return res=0;
	res=0;
	if(y==x)res=cant[x];
	fore(i,1,x){
		if(y-i<0)continue;
		ll t=cant[i]*f(x-1-i,y-i)%MOD;
		t=t*comb[y][i]%MOD;
		res=add(res,t);
	}
	//cout<<x<<" "<<y<<" "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll n; cin>>n>>MOD;
	cant[0]=1;
	cant[1]=1;
	fore(i,2,n+1){
		mset(sump2,0);
		for(ll j=i-1;j>=0;j--){
			fore(k,0,i){
				ll val=0;
				if(i<=2)val=(j!=k);
				else if(j!=k){
					if(j<k){
						val=add(val,sump[0][j]);
					}else{
						val=add(val,sump[j][j-1]);
					}
				}
				//cout<<i<<" "<<j<<" "<<k<<" -> "<<val<<"\n";
				sump2[j][k]=add(sump2[j+1][k],val);
			}
		}
		swap(sump,sump2);
		fore(j,0,n){
			cant[i]=add(cant[i],sump[0][j]);
		}
	}
	//fore(i,0,n+1)cout<<cant[i]<<" "; 
	//cout<<"\n";
	fore(i,0,MAXN){
		fore(j,0,i+1){
			if(j==0||j==i)comb[i][j]=1;
			else comb[i][j]=add(comb[i-1][j],comb[i-1][j-1]);
		}
	}
	mset(dp,-1);
	ll res=0;
	fore(i,0,n+1)res=add(res,f(n,i));
	cout<<res<<"\n";
	
	return 0;
}