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
int n,a[N],h;
signed main(){
	int T=read();while(T--){
		n=read(),h=read();
		For(i,1,n)a[i]=read();sort(a+1,a+1+n);
		int ans=h/(a[n]+a[n-1])*2;h%=(a[n]+a[n-1]);
		if(h>0)h-=a[n],ans++;
		if(h>0)h-=a[n-1],ans++;
		cout<<ans<<endl;
	}
	return 0;
}