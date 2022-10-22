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
int n,a[N],b[N];
signed main(){
	int T=read();while(T--){
		n=read();For(i,1,n)a[i]=read();For(i,1,n)b[i]=read();
		sort(a+1,a+1+n),sort(b+1,b+1+n);int fl=1;
		For(i,1,n)fl&=(a[i]==b[i]||a[i]+1==b[i]);
		puts(fl?"Yes":"No");
	}
	return 0;
}