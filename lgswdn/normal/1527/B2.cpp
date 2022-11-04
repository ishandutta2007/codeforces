#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=1e3+9;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int T,n;
char s[N];

int main() {
	T=read();
	while(T--) {
		scanf("%d%s",&n,s+1);
		int cnt=0;
		rep(i,1,n) cnt+=(s[i]=='0');
		bool pal=1;
		rep(i,1,(n+1)/2) if(s[i]!=s[n+1-i]) pal=0;
		if(pal) {
			if(cnt==1) puts("BOB");
			else if(cnt%2==1) puts("ALICE");
			else puts("BOB");
		} else {
			if(cnt==2&&n%2==1&&s[(n+1)/2]=='0') puts("DRAW");
			else puts("ALICE"); 
		}
	}
	return 0;
}