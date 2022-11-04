#include<bits/stdc++.h>
#define int long long
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

int T,n,m;
char s[N];

signed main() {
	T=read();
	while(T--) {
		n=read(), m=read();
		scanf("%s",s+1);
		while(m--) {
			bool cg=0;
			s[0]='0', s[n+1]='0';
			vector<int>vec;
			rep(i,1,n) if(s[i-1]-'0'+s[i+1]-'0'==1&&s[i]=='0') {
				cg=1;
				vec.push_back(i);
			}
			for(auto v:vec) s[v]='1';
			if(!cg) break;
		}
		rep(i,1,n) putchar(s[i]); putchar('\n');
	}
	return 0;
}