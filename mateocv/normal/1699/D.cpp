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

const int MAXN=5050;

bool val[MAXN][MAXN];

int cant[MAXN][MAXN];

int dp[MAXN][MAXN];

ll n;

vector<ll> a;

int INF=1e9;

int f(ll x, ll y){
	auto &res=dp[x][y];
	if(res>=0)return res;
	if(x==n)return res=(val[y][x-1]?0:-INF);
	res=f(x+1,y);
	if((y==0||a[y-1]==a[x])&&(x==0||val[y][x-1]))res=max(res,f(x+1,x+1)+1);
	//cout<<x<<" "<<y<<" "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		a.clear();
		a.resize(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		fore(j,0,n){
			cant[0][j]=0;
		}
		fore(i,0,n){
			fore(j,0,n){
				cant[i+1][j]=cant[i][j]+(a[i]==j);
			}
		}
		fore(i,0,n+1)fore(j,0,n+1)val[i][j]=(i==j+1);
		fore(i,0,n){
			ll va=a[i],c=1;
			fore(j,i+1,n){
				if(va==a[j])c++;
				else c--;
				if(c<0){
					va=a[j];
					c=-c;
				}
				if(i%2==j%2)val[i][j]=0;
				else if(va!=-1&&cant[j+1][va]-cant[i][va]>(j+1-i)/2)val[i][j]=0;
				else val[i][j]=1;
			}
		}
		fore(i,0,n+1){
			fore(j,0,n+1){
				dp[i][j]=-1;
			}
		}
		/*
		fore(i,0,n+1){
			fore(j,0,n+1){
				cout<<i<<" "<<j<<": "<<val[i][j]<<"\n";
			}
		}
		*/
		cout<<f(0,0)<<"\n";
	}
	
	return 0;
}