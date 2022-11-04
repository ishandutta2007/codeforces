#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int T,n,cnt[2];

signed main() {
	T=read();
	while(T--) {
		n=read(); n*=2;
		cnt[0]=cnt[1]=0;
		rep(i,1,n) cnt[read()%2]++;
		if(cnt[0]==cnt[1]) puts("YES");
		else puts("NO");
	}
	return 0;
}