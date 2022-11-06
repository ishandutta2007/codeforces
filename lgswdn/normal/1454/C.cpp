#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=2e5+9;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int a[N],cnt[N];

int main() {
	int T=read();
	while(T--) {
		int n=read(),ans=n+1;
		rep(i,1,n) a[i]=read(), cnt[a[i]]=0;
		rep(i,2,n) {
			if(a[i]!=a[i-1]) cnt[a[i-1]]++;
		}
		rep(i,1,n) if(a[1]!=i) cnt[i]++;
		rep(i,1,n) ans=min(ans,cnt[a[i]]);
		printf("%d\n",ans);
	}
	return 0;
}