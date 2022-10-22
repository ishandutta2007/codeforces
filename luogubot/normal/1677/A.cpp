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
const int N=5e3+10;int n,a[N],f[N][N],g[N][N];
signed main(){
	int TTT=read();while(TTT--){
		n=read();For(i,0,n+1)For(j,0,n+1)f[i][j]=g[i][j]=0;
		For(i,1,n)a[i]=read(),f[i][a[i]]++,g[i][a[i]]++;;
		For(i,1,n)For(j,1,n)f[i][j]+=f[i-1][j]+f[i][j-1]-f[i-1][j-1];
		Rof(i,n,1)For(j,1,n)g[i][j]+=g[i+1][j]+g[i][j-1]-g[i+1][j-1];
		long long ans=0;
		For(b,2,n-2)For(c,b+1,n-1)ans+=1ll*f[b-1][a[c]-1]*g[c+1][a[b]-1];
		cout<<ans<<endl;
	}
	return 0;
}