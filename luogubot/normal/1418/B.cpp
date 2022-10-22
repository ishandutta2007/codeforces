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
const int N=110;
int n,a[N],l[N],b[N];
signed main(){
	int T=read();while(T--){
		For(i,1,n=read())a[i]=read();
		For(i,1,n)l[i]=read();
		int m=0;
		For(i,1,n)if(!l[i])b[++m]=a[i];
		sort(b+1,b+1+m);
		For(i,1,n)if(!l[i])a[i]=b[m--];
		For(i,1,n)printf("%d ",a[i]);puts("");
	}
	return 0;
}