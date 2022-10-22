#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
int dir[4][2]={1,0,-1,0,0,1,0,-1};
const int N=23,inf=1e6;
int n,m,sx,sy,t,val[N];
char mp[N][N];
int dp[N][N][1<<8];
struct node{
	int x,y,S,v;
	bool operator < (const node &a) const {return v>a.v;}
};queue<node> q;
void solve(){
	memset(dp,0x3f,sizeof dp),dp[sx][sy][0]=0,q.push((node){sx,sy,0,0});
	while(!q.empty()){
		node now=q.front();q.pop();
		int x=now.x,y=now.y,S=now.S,v=dp[x][y][S];
		For(i,0,3){
			int dx=x+dir[i][0],dy=y+dir[i][1];
			if(dx<1||dx>n||dy<1||dy>m||mp[dx][dy]=='#'||isdigit(mp[dx][dy]))continue;
			int dS=S,dv=v+1;
			if(i==0){For(yy,1,y-1)if(isdigit(mp[dx][yy]))dS^=(1<<mp[dx][yy]-'1');}
			if(i==1){For(yy,1,y-1)if(isdigit(mp[x][yy]))dS^=(1<<mp[x][yy]-'1');}
			if(dp[dx][dy][dS]>dv){
				dp[dx][dy][dS]=dv;
				q.push((node){dx,dy,dS,dv});
			}
		}
	}int ans=0;For(S,0,(1<<t)-1){
		int ret=-dp[sx][sy][S];
		For(i,1,t)if(S>>i-1&1)ret+=val[i];
		ans=max(ans,ret);
	}cout<<ans<<endl;
}
signed main(){
	n=read(),m=read();For(i,1,n)scanf("%s",mp[i]+1);
	For(i,1,n)For(j,1,m){
		if(mp[i][j]=='S')sx=i,sy=j;
		if(isdigit(mp[i][j]))t=max(t,mp[i][j]-'0');
	}For(i,1,t)val[i]=read();For(i,1,n)For(j,1,m)if(mp[i][j]=='B')
		mp[i][j]=(++t)+'0',val[t]=-inf;
	solve();
	return 0;
}