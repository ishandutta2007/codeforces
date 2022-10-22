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
int n;char s[N];
int nxt[N][4];
signed main(){
	int T=read();while(T--){
		scanf("%s",s+1),n=strlen(s+1);
		For(i,1,n)For(j,1,3)nxt[i][j]=n+1;
		int ans=1e9;
		Rof(i,n,1){
			if(i<n)For(j,1,3)nxt[i][j]=nxt[i+1][j];
			nxt[i][s[i]-'0']=i;int mn=n+1,mx=0;
			For(j,1,3)mn=min(mn,nxt[i][j]),mx=max(mx,nxt[i][j]);
			if(mx<=n)ans=min(ans,mx-mn+1);
		}if(ans<=n)cout<<ans<<endl;
		else puts("0");
	}
	return 0;
}