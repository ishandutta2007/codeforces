#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=1e3+10;
int f[N][N],n,m;
signed main(){
	int T=read();while(T--){
		memset(f,0,sizeof f);
		n=read(),m=read();For(i,1,n){
			int x=read(),y=read();
			f[x][y]+=x*y;
		}For(i,1,1000)For(j,1,1000)f[i][j]+=f[i-1][j]+f[i][j-1]-f[i-1][j-1];
		while(m--){
			int x1=read()+1,y1=read()+1,x2=read()-1,y2=read()-1;
			cout<<(x1<=x2&&y1<=y2?(f[x2][y2]-f[x1-1][y2]-f[x2][y1-1]+f[x1-1][y1-1]):0)<<endl;
		}
	}
	return 0;
}