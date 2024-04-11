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
int mx[100],n;
signed main(){
	int T=read();while(T--){
		For(i,1,10)mx[i]=-1e8;
		For(i,1,n=read()){
			int b=read(),d=read();mx[d]=max(mx[d],b);
		}int ans=0;For(i,1,10)ans+=mx[i];
		if(ans<0)puts("MOREPROBLEMS");else cout<<ans<<endl;
	}
	return 0;
}