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

ll MOD=1000000007;

ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

const int MAXN=202;

ll c[2*MAXN][MAXN][MAXN];

ll comb(ll n, ll k){
	if(k>n)return 0;
	//k=min(k,n-k);
	ll res=1,resd=1;
	fore(i,0,k){
		res=res*(n-i)%MOD;
		resd=resd*(i+1)%MOD;
	}
	//cout<<n<<" "<<k<<" -> "<<res<<" "<<resd<<" "<<res*fpow(resd,MOD-2)%MOD<<endl;
	return res*fpow(resd,MOD-2)%MOD;
}

ll pre[2*MAXN][MAXN];
ll pos[2*MAXN][MAXN];

ll n;

ll add(ll x, ll y){
	if(x+y>=MOD)return x+y-MOD;
	return x+y;
}

ll inv[MAXN];

ll fact[MAXN][MAXN];

int main(){FIN;
	ll k; cin>>n>>k;
	fore(i,0,2*MAXN){
		fore(j,0,MAXN){
			c[i][j][0]=1;
			c[i][j][1]=comb(n-i,j);
		}
	}
	inv[0]=1;
	fore(i,1,MAXN)inv[i]=fpow(i,MOD-2);
	fore(i,0,MAXN)fact[i][0]=1;
	fact[0][1]=1;
	fore(i,1,MAXN)fact[i][1]=fact[i-1][1]*i%MOD;
	fore(j,2,MAXN){
		fore(i,0,MAXN){
			fact[i][j]=fact[i][j-1]*fact[i][1]%MOD;
		}
	}
	fore(ii,2,MAXN){
		fore(i,0,2*MAXN){
			fore(j,0,MAXN){
				c[i][j][ii]=0;
				if(i+j<2*MAXN){
					c[i][j][ii]=c[i][j][1]*c[i+j][j][ii-1]%MOD;
					if(j)c[i][j][ii]=c[i][j][ii]*inv[ii]%MOD;
				}
			}
		}
	}
	fore(i,0,2*MAXN){
		fore(j,1,MAXN){
			fore(ii,0,MAXN){
				c[i][j][ii]=c[i][j][ii]*fact[j-1][ii]%MOD;
			}
		}
	}
	/*
	ll &res=dp[x][y][z];
	if(res>=0)return res;
	res=0;
	if(y==0)return res=(x<=n);
	fore(i,0,n+1){
		if(y-i*z>=0&&z+1<MAXN)res=add(res,c[x][z+1][i]*f(x+i*(z+1),y-i*z,z+1)%MOD);
		else break;
	}
	return res;
	*/
	for(ll z=MAXN-1;z>=1;z--){
		fore(x,0,2*MAXN-z-1){
			fore(y,0,min(MAXN,2*MAXN-x)){
				ll &res=pos[x][y];
				res=0;
				if(y==0)res=(x<=n);
				else{
					fore(i,0,n+1){
						if(y-i*z>=0&&z+1<MAXN&&x+i*(z+1)<2*MAXN)
							res=add(res,c[x][z+1][i]*pre[x+i*(z+1)][y-i*z]%MOD);
						else break;
					}
				}
			}
		}
		swap(pre,pos);
	}
	ll res[2]={1,0};
	fore(i,1,k+1){
		res[i&1]=add(res[i&1],pre[0][i]);
		cout<<res[i&1]<<" ";
	}
	cout<<"\n";
	
	return 0;
}