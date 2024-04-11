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
const int N=3e5+10;
int n,a[N],b[N];
signed main(){
	int T=read();while(T--){
		int s=0,mn=1e18;
		For(i,1,n=read())a[i]=read(),b[i]=read(),s+=a[i];
		For(i,1,n)b[i]=min(b[i],a[i%n+1]),mn=min(mn,b[i]),s-=b[i];
		cout<<s+mn<<endl;
	}
	return 0;
}