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
const int N=1e4+10,M=2e3+10;
bitset<M> S,T;
int n,a[N];
signed main(){
	int TTT=read();while(TTT--){
		int mx=0;For(i,1,n=read())mx=max(mx,a[i]=read());
		int l=mx,r=2*mx;while(l<=r){
			int m=l+r>>1;
			S.reset(),T.reset();
			For(i,0,m)S.set(i),T.set(i);
			For(i,1,n)S=((S<<a[i])|(S>>a[i]))&T;
			if(S.count())r=m-1;
			else l=m+1;
		}printf("%d\n",r+1);
	}
	return 0;
}