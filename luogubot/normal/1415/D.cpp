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
int n,a[N];
signed main(){
	int T=1;while(T--){
		For(i,1,n=read())a[i]=a[i-1]^read();int ans=1e9;
		For(i,1,n)Rof(j,i-1,max(0,i-32))For(k,i+1,min(n,i+32)){
			if((a[i]^a[j])>(a[k]^a[i]))ans=min(ans,k-j-2);
		}if(ans<=n)cout<<ans<<endl;
		else puts("-1");
	}
	return 0;
}//fds