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
const int N=110;
int n,t[N],c;
signed main(){
	int T=read();while(T--){
		memset(t,0,sizeof t);
		n=read(),c=read();For(i,1,n)t[read()]++;
		int ans=0;For(i,1,100)ans+=min(t[i],c);
		cout<<ans<<endl;
	}
	return 0;
}