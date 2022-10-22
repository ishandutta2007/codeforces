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
int n,p,k,f[N];char a[N];
signed main(){
	int T=read();while(T--){
		n=read(),p=read(),k=read();scanf("%s",a+1);
		int x=read(),y=read();memset(f,0,sizeof f);
		Rof(i,n,1){
			f[i]=f[i+k]+(a[i]=='0');
		}int ans=1e9;For(i,0,n-p){
			ans=min(ans,y*i+x*f[i+p]);
		}cout<<ans<<endl;
	}
	return 0;
}