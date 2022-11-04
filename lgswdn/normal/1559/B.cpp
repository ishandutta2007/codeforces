#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=109;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}

int T,n;
char s[N];

signed main() {
	T=read();
	while(T--) {
		scanf("%lld%s",&n,s+1);
		int l=0;
		rep(i,1,n) {
			if(s[i]=='?'&&s[i-1]!='?') l=i;
			if(s[i]=='?'&&s[i+1]!='?') {
				int r=i;
				if(l==1) {
					per(i,r,l) {
						if(s[i+1]=='B') s[i]='R';
						else s[i]='B';
					}
				} else if(r==n) {
					rep(i,l,r) {
						if(s[i-1]=='B') s[i]='R';
						else s[i]='B';
					}
				} else {
					while(l<=r) {
						if(s[l-1]=='B') s[l++]='R';
						else s[l++]='B';
						if(s[r+1]=='B') s[r--]='R';
						else s[r--]='B';
					}
				}
			}
		}
		rep(i,1,n) putchar(s[i]); putchar('\n');
	}
	return 0;
}