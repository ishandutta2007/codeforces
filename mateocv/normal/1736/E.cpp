#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define f(a,b,c,d) dp[a][b][c][d]
using namespace std;
typedef int ll;

ll n;
vector<ll> a;

const int MAXN=505;

ll dp[MAXN][MAXN][MAXN][2];

int main(){FIN;
	cin>>n;
	a.resize(n);
	fore(i,0,n)cin>>a[i];
	for(ll x=n;x>=0;x--){
		for(ll y=n;y>=0;y--){
			fore(z,0,n+1){
				fore(b,0,2){
					ll &res=dp[x][y][z][b];
					if(x==n)res=0;
					else{
						res=0;
						if(y&&z&&b)res=max(res,f(x+1,y,z,1)+a[y-1]);
						if(y<SZ(a))res=max(res,f(x,y+1,z,0));
						if(!b&&abs(x-y+1)<=z&&y&&y>x)res=max(res,f(x+1,y,z-abs(x-y+1)+1,1)+a[y-1]);
						if(y<=x)res=max(res,f(x+1,x+1,z+1,1)+a[x]);
					}
				}
			}
		}
	}
	cout<<dp[0][0][1][1]<<"\n";
	
	return 0;
}