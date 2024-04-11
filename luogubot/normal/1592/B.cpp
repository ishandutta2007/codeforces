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
const int N=1e5+10;
int n,a[N],b[N],x;
signed main(){
	int T=read();while(T--){
		n=read(),x=read();For(i,1,n)a[i]=b[i]=read();
		if(n-x+1>x)puts("YES");
		else{
			sort(b+1,b+1+n);int fl=1;
			For(i,n-x+1,x)fl&=(a[i]==b[i]);
			puts(fl?"YES":"NO");
		}
	}
	return 0;
}