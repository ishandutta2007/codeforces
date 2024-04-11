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
const int N=110;
int n,m;char a[N][N];
int vis[N][N],idx;
inline bool in(int tx,int ty){return 1<=tx&&tx<=n&&1<=ty&&ty<=m;}
int dir[8][2]={1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,1,-1,-1};
signed main(){
//	freopen("out","w",stdout);
	int T=read();while(T--){
		memset(a,0,sizeof a),idx=0;
		memset(vis,0,sizeof vis);int fl=1;
		n=read(),m=read();For(i,1,n)scanf("%s",a[i]+1);
		For(i,1,n)For(j,1,m)if(a[i][j]=='*'){
			For(dx,-1,1)For(dy,-1,1)if(dx&&dy){
				int tx=i+dx,ty=j+dy;
				if(in(i,ty)&&in(tx,j)&&a[i][ty]=='*'&&a[tx][j]=='*'){
					fl&=!vis[i][j]&&!vis[i][ty]&&!vis[tx][j];
					vis[i][j]=vis[i][ty]=vis[tx][j]=++idx;
				}
			}
		}
		For(x,1,n)For(y,1,m)if(a[x][y]=='*')For(d,0,7){
			int dx=x+dir[d][0],dy=y+dir[d][1];
			if(in(dx,dy)&&a[dx][dy]=='*'&&vis[x][y]!=vis[dx][dy])fl=0;
		}
		For(i,1,n)For(j,1,m)if(a[i][j]=='*')fl&=(vis[i][j]>0);
//		For(i,1,n)For(j,1,m){
//			printf("%d%c",vis[i][j]," \n"[j==m]);
//		}
		puts(fl?"YES":"NO");
	}
	return 0;
}