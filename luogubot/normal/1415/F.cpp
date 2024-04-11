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
bool ST;
const int N=5e3+10;
int n,t[N],p[N],c[N];
bitset<N> f[N];
inline int absll(int a){return a<0?-a:a;}
inline int dis(int x,int y){return absll(p[x]-p[y]);}
inline bool to(int x,int y){return t[y]-t[x]>=dis(x,y);}
inline void gmin(int &a,int b){(a>b)&&(a=b);}
bool ED;
signed main(){
//	printf("%.2lf MB\n",abs(&ED-&ST)/1024.0/1024.0);
	For(i,1,n=read())t[i]=read(),p[i]=read();
	//f[i][j](j>i): ij 
	memset(c,0x3f,sizeof c),c[0]=0;For(i,0,n-1)if(c[i]<=t[i]){
		//1.1 (i) -> i+1
		gmin(c[i+1],max(t[i],c[i]+dis(i,i+1)));
		//1.2 (i) -> j(>i+1) -> i+1
		For(j,i+2,n)if(max(t[i],c[i]+dis(i,j))+dis(j,i+1)<=t[i+1])f[i+1][j]=1;
		//2.1 i -> i+1
		if(to(i,i+1))f[i+1]|=f[i],f[i+1][i+1]=0;
		//2.2.1 i -> (i+1) -> i+2
		if(f[i][i+1])gmin(c[i+2],max(t[i+1],t[i]+dis(i,i+2)));
		//2.2.2 i -> j(>i+2) ->i+2
		if(f[i][i+1])For(j,i+3,n)if(max(t[i+1],t[i]+dis(i,j))+dis(j,i+2)<=t[i+2])f[i+2][j]=1;
	}puts(c[n]<=t[n]||f[n-1][n]?"YES":"NO");
	return 0;
}