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
const int N=1e6+10;
int n,a[N],b[N],c[N],pre[N];
signed main(){
	For(i,1,n=read())a[i]=read();int ans=0;
	Rof(i,19,0){
		For(j,1,n)b[j]=b[j-1]+(a[j]>>i&1),c[j]^=((b[j]&1)<<i);
		memset(pre,-1,sizeof pre),pre[0]=0;
		For(j,1,n){
			if(pre[c[j]]==-1)pre[c[j]]=j;
			else{
				int k=pre[c[j]];
				if(b[j]-b[k]==j-k)ans=max(ans,j-k);
				else pre[c[j]]=j;
			}
		}
	}cout<<ans<<endl;
	return 0;
}//dsadsa//dasdsa