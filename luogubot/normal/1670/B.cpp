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
int n,ban[200];
char s[N],o[5];
signed main(){
	int T=read();while(T--){
		n=read(),scanf("%s",s+1);
		memset(ban,0,sizeof ban);
		int k=read();For(i,1,k)scanf("%s",o),ban[o[0]]=1;
		int lst=1,ans=0;For(i,1,n){
			if(ban[s[i]]){
				ans=max(ans,i-lst),lst=i;
			}
		}printf("%lld\n",ans);
	}
	return 0;
}