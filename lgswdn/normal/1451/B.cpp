#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=109;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int T,n,q,ans,s[N];
char c[N];

int main() {
	T=read();
	while(T--) {
		n=read(),q=read();
		scanf("%s",c+1);
		ans=0;
		rep(i,1,n) s[i]=s[i-1]+(c[i]=='1');
		while(q--) {
			ans=0;
			int l=read(), r=read();
			if(l!=1) {
				if(c[l]=='0'&&s[l-1]!=l-1) ans=1;
				else if(c[l]=='1'&&s[l-1]!=0) ans=1;
			}
			if(r!=n) {
				if(c[r]=='0'&&s[n]-s[r]!=n-r) ans=1;
				else if(c[r]=='1'&&s[n]-s[r]!=0) ans=1;
			}
			if(ans==1) puts("YES");
			else puts("NO");
		}
	}
	return 0;
} //