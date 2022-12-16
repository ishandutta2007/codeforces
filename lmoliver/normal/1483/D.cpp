#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
int read(){int x;scanf("%d",&x);return x;}

const int N=666;
const int INF=1e9+7;
int e[N][N];
int d[N][N];
int req[N][N];
int need[N];
bool ok[N][N];

int main(){
	int n=read(),m=read();
	F(i,1,n)F(j,1,n)e[i][j]=d[i][j]=i==j?0:INF;
	D(_,m){
		int u=read(),v=read(),w=read();
		e[u][v]=e[v][u]=d[u][v]=d[v][u]=w;
	}
	F(k,1,n)F(i,1,n)F(j,1,n)if(i!=k&&j!=k&&i!=j)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	int q=read();
	D(_,q){
		int u=read(),v=read(),l=read();
		req[u][v]=req[v][u]=l;
	}
	F(i,1,n){
		F(j,1,n){
			need[j]=-INF;
			F(k,1,n)need[j]=max(need[j],req[i][k]-d[j][k]);
		}
		F(j,1,n)F(k,1,n){
			if(d[i][j]+e[j][k]<=need[k]){
				ok[j][k]=true;
				// cerr<<"ok "<<i<<" "<<j<<" "<<k<<endl;
			}
		}
	}
	int ans=0;
	F(i,1,n)F(j,i+1,n)if(i!=j)ans+=ok[i][j]||ok[j][i];
	printf("%d\n",ans);
	return 0;
}