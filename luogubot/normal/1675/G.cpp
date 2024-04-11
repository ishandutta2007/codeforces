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
const int N=255;
int n,m,sum[N],f[N][N][N];
inline void gmin(int &a,int b){(a>b)&&(a=b);}
signed main(){
	n=read(),m=read();
	For(i,1,n)sum[i]=sum[i-1]+read();
	memset(f,0x3f,sizeof f);For(i,0,m)f[1][i][i]=abs(i-sum[1]);
	For(i,1,n-1)For(j,0,m/i)For(S,1,m)if(f[i][j][S]<50000)For(l,0,min(j,m/(i+1)))if(S+l<=m)gmin(f[i+1][l][S+l],f[i][j][S]+abs(S+l-sum[i+1]));
	int ans=1e9;For(S,0,m)gmin(ans,f[n][S][m]);cout<<ans<<endl;
	return 0;
}