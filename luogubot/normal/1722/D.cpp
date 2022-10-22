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
int n,d[N];char s[N];
signed main(){
	int T=read();while(T--){
		n=read(),scanf("%s",s+1);
		int ans=0;
		For(i,1,n){
			int x=0;
			if(s[i]=='L')x=i-1;
			else x=n-i;
			ans+=x,d[i]=max(i-1,n-i)-x;
		}sort(d+1,d+1+n);Rof(i,n,1)ans+=d[i],printf("%lld ",ans);puts("");
	}
	return 0;
}