#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
using namespace std;
const int N=3e5+9;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int T,n,a[N],lst[N],md[N],f[N];

int main() {
	T=read();
	while(T--) {
		memset(lst,0,sizeof(lst));
		memset(md,0,sizeof(md)); 
		memset(f,0x3f,sizeof(f));
		n=read();
		rep(i,1,n) a[i]=read();
		rep(i,1,n) {
			md[a[i]]=max(md[a[i]],i-lst[a[i]]);
			lst[a[i]]=i;
		}
		rep(i,1,n) md[a[i]]=max(md[a[i]],n+1-lst[a[i]]);
		rep(i,1,n) f[md[a[i]]]=min(f[md[a[i]]],a[i]);
		int pos=0,ans=0x3f3f3f3f;
		rep(i,1,n) {
			f[i]=min(f[i],f[i-1]);
			printf("%d ",f[i]<0x3f3f3f3f ? f[i] : -1);
		}
		puts("");
	}
	return 0;
}