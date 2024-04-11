#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define endout fflush(stdout)
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=1e5+10;
int n,a[N];
int val(int i){
	if(i<1||i>n)return n+1;
	if(a[i])return a[i];
	printf("? %d\n",i),endout;
	return a[i]=read();
}
signed main(){
	n=read();
	if(n==1)return puts("! 1"),endout,0;
	if(n==2){
		int _1=val(1);
		if(_1==1)puts("! 1");
		else puts("! 2");
		endout;return 0;
	}int l=1,r=n;while(l<r){
		int m=l+r>>1;
		int v1=val(m),v2=val(m+1);
		if(v1<v2)r=m;
		else l=m+1;
	}For(i,l-1,r+1)a[i]=val(i);
	For(i,l-1,r+1){
		if(i==0||i==n+1)continue;
		if(a[i]<a[i-1]&&a[i]<a[i+1]){
			printf("! %d\n",i),endout;
			return 0;
		}
	}
	return 0;
}