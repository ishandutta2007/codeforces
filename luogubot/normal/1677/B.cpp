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
const int N=1e6+10;int n,m;char s[N];
int h[N],g[N],f[N],a[N];
signed main(){
	int TTT=read();while(TTT--){
		n=read(),m=read(),scanf("%s",s+1);int l=n*m;
		For(i,1,n*m)h[i]=f[i]=g[i]=0,a[i]=a[i-1]+(s[i]=='1');
		For(i,1,n*m){
			int x=a[i]-(i<m?0:a[i-m]);
			if(x)g[i]++;
		}For(i,m+1,l)g[i]+=g[i-m];
		For(i,1,l)if(s[i]=='1'&&!h[(i-1)%m+1]){
			h[(i-1)%m+1]=1,f[i]++;
		}For(i,1,l)f[i]+=f[i-1];
		For(i,1,l)printf("%d ",f[i]+g[i]);puts(""); 
	}
	return 0;
}