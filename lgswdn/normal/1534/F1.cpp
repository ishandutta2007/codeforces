#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=4e5+9;
typedef pair<int,int> pii;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}
inline bool issym(char c) {return c=='#'||c=='.';}

int n,m,l[N],r[N],f[N],a[N],ans;
vector<char>s[N];

inline int hsh(int x,int y) {return (x-1)*m+y;}

inline bool lgl(int x,int y) {return x>0&&x<=n&&y>0&&y<=m&&s[x][y]=='#';}
void dfs1(int x,int y,int tag) {
	if(l[hsh(x,y)]) return; l[hsh(x,y)]=tag;
	if(x<n) dfs1(x+1,y,tag);
	if(lgl(x-1,y)) dfs1(x-1,y,tag);
	if(lgl(x,y-1)) dfs1(x,y-1,tag);
	if(lgl(x,y+1)) dfs1(x,y+1,tag);
}
void dfs2(int x,int y,int tag) {
	if(r[hsh(x,y)]) return; r[hsh(x,y)]=tag;
	if(x<n) dfs2(x+1,y,tag);
	if(lgl(x-1,y)) dfs2(x-1,y,tag);
	if(lgl(x,y-1)) dfs2(x,y-1,tag);
	if(lgl(x,y+1)) dfs2(x,y+1,tag);
}

int main() {
	n=read(), m=read();
	rep(i,1,n) s[i].resize(m+1);
	rep(i,1,n) {
		char c=getchar(); int len=0;
		while(!issym(c)) c=getchar();
		while(issym(c)) s[i][++len]=c, c=getchar();
	}
	rep(j,1,m) a[j]=read();
	rep(j,1,m) rep(i,1,n) if(s[i][j]=='#') dfs1(i,j,j);
	per(j,m,1) rep(i,1,n) if(s[i][j]=='#') dfs2(i,j,j);
	rep(j,1,m+2) f[j]=m+2;
	rep(j,1,m) per(i,n,1) if(s[i][j]=='#') {
		a[j]--;
		if(a[j]==0) f[l[hsh(i,j)]]=min(f[l[hsh(i,j)]],r[hsh(i,j)]+1);
	}
	per(j,m,1) f[j]=min(f[j],f[j+1]); int cur=f[1];
	while(cur<m+2) ans++, cur=f[cur];
	printf("%d\n",ans);
	return 0;
}