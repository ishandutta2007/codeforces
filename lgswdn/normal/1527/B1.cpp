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
		int cnt=0, ca=0, cb=0;
		rep(i,1,(n+1)/2) cnt+=(s[i]-'0'+s[n+1-i]-'0')%2;
		cb+=cnt; cnt=0;
		rep(i,1,(n+1)/2) {
			if(s[i]=='0'&&s[n+1-i]=='1') s[i]='1';
			else if(s[i]=='1'&&s[n+1-i]=='0') s[n+1-i]='0';
			else if(s[i]=='0'&&s[n+1-i]=='0') cnt+=1+(i!=n+1-i);
		}
		if(cnt) {
			if(cnt==1) ca++;
			else if(cnt%2==1) cb++;
			else ca+=2;
		}
		if(ca<cb) puts("ALICE");
		else if(ca==cb) puts("DRAW");
		else puts("BOB");
	}
	return 0;
}