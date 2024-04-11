#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define MOD 1000000007
using namespace std;

typedef long long ll;

int c[64][64];
int n,a,b,k;
int d[64][64][2];
queue<pair<pair<int,int>,int> > q;
int dp[64][64][2];

int f(int a0, int b0, int w0){
	if(dp[a0][b0][w0]>=0)return dp[a0][b0][w0];
	dp[a0][b0][w0]=0;
	fore(a1,0,a0+1){
		fore(b1,0,b0+1){
			if(!a1&&!b1)continue;
			if(a1*50+b1*100>k)continue;
			int a2=a-a0+a1,b2=b-b0+b1,w2=w0^1;
			if(d[a2][b2][w2]==d[a0][b0][w0]+1){
				ll r=(1LL*c[a0][a1]*c[b0][b1])%MOD;
				dp[a0][b0][w0]+=(((1LL*c[a0][a1]*c[b0][b1])%MOD)*f(a2,b2,w2))%MOD;
				dp[a0][b0][w0]%=MOD;
			}
		}
	}
	return dp[a0][b0][w0];
}

int main(){
	fore(i,0,64){
		c[i][0]=c[i][i]=1;
		fore(j,1,i)c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
	}
	scanf("%d%d",&n,&k);
	fore(i,0,n){int t;scanf("%d",&t);if(t==50)a++;else b++;}
	memset(d,-1,sizeof(d));
	d[a][b][0]=0;
	q.push(mp(mp(a,b),0));
	while(!q.empty()){
		int a0=q.front().fst.fst,b0=q.front().fst.snd,w0=q.front().snd;
		q.pop();
		fore(a1,0,a0+1){
			fore(b1,0,b0+1){
				if(!a1&&!b1)continue;
				if(a1*50+b1*100>k)continue;
				int a2=a-a0+a1,b2=b-b0+b1,w2=w0^1;
				if(d[a2][b2][w2]<0){
					d[a2][b2][w2]=d[a0][b0][w0]+1;
					q.push(mp(mp(a2,b2),w2));
				}
			}
		}
	}
	printf("%d\n",d[a][b][1]);
	if(d[a][b][1]<0){puts("0");return 0;}
	memset(dp,-1,sizeof(dp));
	dp[a][b][1]=1;
	printf("%d\n",f(a,b,0));
	return 0;
}