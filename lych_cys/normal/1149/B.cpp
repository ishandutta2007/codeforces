#include<bits/stdc++.h>
#define ll long long
#define inf 1010000000
#define infll 1010000000000000000ll
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
#define N 259
#define M 100009
using namespace std;

int n,m,b[M][26],dp[N][N][N],len[4]; char s[9],a[M],ch[4][M];
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
ll readll(){
	ll x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
int main(){
	scanf("%d%d%s",&n,&m,a+1);
	int i,j,k,x,u,v,w;
	for (i=0; i<26; i++) b[n][i]=b[n+1][i]=n+1;
	for (i=n-1; i>=0; i--){
		for (j=0; j<26; j++) b[i][j]=b[i+1][j];	
		b[i][a[i+1]-'a']=i+1;
	}
	dp[0][0][0]=0;
	for (i=1; i<=m; i++){
		scanf("%s",s);
		if (s[0]=='+'){
			scanf("%d%s",&x,s); ch[x][++len[x]]=s[0];
			for (j=0; j<N; j++)
				for (k=0; k<N; k++){
					if (x==1){
						u=len[1]; v=j; w=k;
					} else if (x==2){
						u=j; v=len[2]; w=k;
					} else{
						u=j; v=k; w=len[3];
					}
					if (u>len[1] || v>len[2] || w>len[3]) continue;
					dp[u][v][w]=n+1;
					if (u) dn(dp[u][v][w],b[dp[u-1][v][w]][ch[1][u]-'a']);
					if (v) dn(dp[u][v][w],b[dp[u][v-1][w]][ch[2][v]-'a']);
					if (w) dn(dp[u][v][w],b[dp[u][v][w-1]][ch[3][w]-'a']);
				}
		} else{
			scanf("%d",&x); len[x]--;
		}
		puts(dp[len[1]][len[2]][len[3]]<=n?"YES":"NO");
	}
	return 0;
}