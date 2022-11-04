#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=509;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int t,n,m;
char s[N][N];

int main() {
	t=read();
	while(t--) {
		n=read(), m=read();
		rep(i,1,n) scanf("%s",s[i]+1);
		if(m%3==1) {
			rep(i,1,n) s[i][m+1]='.'; 
		} else if(m%3==2) {
			rep(i,1,n) s[i][m+1]='.';
			rep(i,1,n) s[i][m+2]='.';
		}
		for(int c=1;c<=m;c+=3) {
			rep(i,1,n) s[i][c]='X';
			if(n==1||s[2][c+1]!='X'&&s[2][c+2]!='X') s[1][c+1]=s[1][c+2]='X';
			else s[2][c+1]=s[2][c+2]='X';
			if(c+3>m) {
				rep(i,1,n) if(s[i][c+1]=='X'||s[i][c+2]=='X') s[i][c+1]=s[i][c+2]='X';
			}
		}
		rep(i,1,n) {
			rep(j,1,m) putchar(s[i][j]);
			putchar('\n');
		}
	}
	return 0;
}