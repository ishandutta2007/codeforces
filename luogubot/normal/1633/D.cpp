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
int n,k,w[N],v[N],f[N],g[N*12];
signed main(){
	memset(f,0x3f,sizeof f);f[1]=0;
	For(i,1,1000)For(x,1,i)f[i+i/x]=min(f[i+i/x],f[i]+1);
	int T=read();while(T--){
		n=read(),k=min(n*12,read());
		For(i,1,n)w[i]=f[read()];For(i,1,n)v[i]=read();
		memset(g,0,sizeof g);
		For(i,1,n)Rof(j,k,w[i])g[j]=max(g[j],g[j-w[i]]+v[i]);
		cout<<g[k]<<endl;
	}
	return 0;
}