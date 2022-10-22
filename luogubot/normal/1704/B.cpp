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
int n,m,a[N];
signed main(){
	int T=read();while(T--){
		n=read(),m=read();
		For(i,1,n)a[i]=read();
		int l=a[1]-m,r=a[1]+m;
		int cnt=0;
		For(i,2,n){
			int L=a[i]-m,R=a[i]+m;
			if(max(l,L)>min(r,R))l=L,r=R,cnt++;
			else l=max(l,L),r=min(r,R);
		}printf("%d\n",cnt);
	}
	return 0;
}