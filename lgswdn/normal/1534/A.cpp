#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=59;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}

int T,n,m;
char s[N][N],t[N][N];

void output() {
	puts("YES");
	rep(i,1,n) {
		rep(j,1,m) putchar(t[i][j]);
		putchar('\n');
	}
}

signed main() {
	T=read();
	while(T--) {
		n=read(), m=read();
		rep(i,1,n) scanf("%s",s[i]+1);
		bool cfl=0;
		rep(i,1,n) rep(j,1,m) {
			if((i+j)%2==1) t[i][j]='R';
			else t[i][j]='W';
			if(t[i][j]=='R'&&s[i][j]=='W'||t[i][j]=='W'&&s[i][j]=='R')
				{cfl=1; break;}
		}
		if(!cfl) {output(); continue;}
		cfl=0;
		rep(i,1,n) rep(j,1,m) {
			if((i+j)%2==1) t[i][j]='W';
			else t[i][j]='R';
			if(t[i][j]=='R'&&s[i][j]=='W'||t[i][j]=='W'&&s[i][j]=='R')
				{cfl=1; break;}
		}
		if(!cfl) {output(); continue;}
		puts("NO");
	}
	return 0;
}