#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef unsigned long long ull;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=109;
char s[N][N];
int n,m,r[N][N],l[N][N];

signed main() {
	int T=read();
	while(T--) {
		n=read(), m=read();
		rep(i,1,n) scanf("%s",s[i]+1);
		rep(i,1,n) {
			r[i][m]=(s[i][m]=='1')*m;
			per(j,m-1,1) {
				if(s[i][j]=='0') r[i][j]=0;
				else if(r[i][j+1]) r[i][j]=r[i][j+1];
				else r[i][j]=j;
			}
		}
		rep(i,1,n) {
			l[i][1]=(s[i][1]=='1');
			rep(j,2,m) {
				if(s[i][j]=='0') l[i][j]=0;
				else if(l[i][j-1]) l[i][j]=l[i][j-1];
				else l[i][j]=j;
			}
		}
		bool flag=1;
		rep(i,2,n) rep(j,1,m) if(s[i][j]=='1'&&s[i-1][j]=='1') {
			if(l[i-1][j]!=l[i][j]||r[i-1][j]!=r[i][j]) {flag=0; break;}
 		}
 		puts(flag?"YES":"NO");
	}
	return 0;
}