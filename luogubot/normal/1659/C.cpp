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
const int N=2e5+10;
int n,a,b,x[N],s1[N],s2[N];
signed main(){
	int T=read();while(T--){
		n=read(),a=read(),b=read();int ans=1e18;For(i,1,n)x[i]=read();
		s1[n+1]=s2[n+1]=0;Rof(i,n,1)
			s1[i]=x[i]-x[i-1]+s1[i+1],
			s2[i]=(x[i]-x[i-1])*(n-i+1)+s2[i+1];
		Rof(i,n,1)ans=min(ans,(s1[1]-s1[i])*(a+b)+s2[i]*b);
		cout<<ans<<endl;
	}
	return 0;
}