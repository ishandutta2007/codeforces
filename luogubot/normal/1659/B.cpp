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
const int N=2e5+10;
int n,k,f[N];char a[N];
signed main(){
	int T=read();while(T--){
		n=read(),k=read(),scanf("%s",a+1);
		For(i,1,n)f[i]=0;
		if(k&1)For(i,1,n)a[i]^=1;
		if(k)For(i,1,n){
			if(a[i]=='0')k--,f[i]++,a[i]^=1;
			if(!k)break;
		}
		f[1]+=k-(k&1);if(k&1)f[n]++,a[n]^=1;
		For(i,1,n)putchar(a[i]);puts("");
		For(i,1,n)printf("%d%c",f[i]," \n"[i==n]);
	}
	return 0;
}