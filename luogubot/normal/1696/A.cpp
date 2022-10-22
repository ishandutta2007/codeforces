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
const int N=2e3+10;
int n,z,a[N];
signed main(){
	int TTT=read();while(TTT--){
		n=read(),z=read();For(i,1,n)a[i]=read();
		int ans=0;
		For(i,1,n)ans=max(ans,max(a[i],a[i]|z));
		printf("%lld\n",ans);
	}
	return 0;
}