#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=2e5+9;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}
inline int read(char *s) {
	char c=getchar(); int tot=0;
	while(!isalpha(c)) c=getchar();
	while(isalpha(c)) {s[++tot]=c; c=getchar();}
	return tot;
}

int T,n,m;
char s[N],t[N];

int main() {
	T=read();
	while(T--) {
		n=read(s), m=read(t);
		if(n<m) {
			puts("NO");
			continue;
		}
		int pos=1+(n-m)%2,j=0;
		for(int i=pos;i<=n;) {
			if(j==m) break;
			if(s[i]==t[j+1]) i++, j++;
			else i+=2;
		}
		if(j==m) puts("YES");
		else puts("NO");
	}
	return 0;
}