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
const int N=400;
int n,a[N][N],b[N];
signed main(){
	n=read();For(i,1,n)b[i]=read();
	For(i,1,n)For(j,1,n)a[i][j]=i*j%n;For(i,1,n){
		int add=(b[i]-a[i][i]+n)%n;
		For(j,1,n)(a[i][j]+=add)%=n;
	}
	For(i,1,n)For(j,1,n)printf("%d%c",a[i][j]," \n"[j==n]);
	return 0;
}