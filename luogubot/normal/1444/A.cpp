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
signed main(){
	int T=read();while(T--){
		int p=read(),q=read();
		if(p%q)cout<<p<<endl;
		else{
			int ans=0;
			for(int x=2;x*x<=q;x++)if(q%x==0){
				int c=0;while(q%x==0)q/=x,c++;
				int res=p;while(res%x==0)res/=x;
				For(i,2,c)res*=x;ans=max(ans,res);
			}if(q>1){
				int x=q;
				int c=0;while(q%x==0)q/=x,c++;
				int res=p;while(res%x==0)res/=x;
				For(i,2,c)res*=x;ans=max(ans,res);
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}