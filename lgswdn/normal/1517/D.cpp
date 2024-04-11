#include<bits/stdc++.h>
#define int long long
#define x(qwq) qwq.first
#define y(qwq) qwq.second
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=509,inf=0x1f1f1f1f1f1f1f1f;
typedef pair<int,int> pii;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,m,k,a[N][N],b[N][N],c[N][N],d[N][N][29];

bool check(int x,int y) {return x>0&&y>0&&x<=n&&y<=m;}
void go(int q,int i,int j,int x,int y,int w) {
	if(!check(x,y)) return;
	d[i][j][q]=min(d[i][j][q],w);
}

signed main() {
	n=read(), m=read(), k=read();
	memset(a,0x3f,sizeof(a)), memset(b,0x3f,sizeof(b)),
	memset(c,0x3f,sizeof(c)), memset(d,0x3f,sizeof(d));
	rep(i,1,n) rep(j,1,m-1) a[i][j]=read();
	rep(i,1,n-1) rep(j,1,m) b[i][j]=read();
	if(k%2==1) {
		rep(i,1,n) {
			rep(j,1,m) printf("-1 ");
			puts("");
		}
		return 0;
	}
	k/=2;
	rep(i,1,n) rep(j,1,m) d[i][j][0]=0;
	rep(q,1,k) rep(i,1,n) rep(j,1,m) {
		go(q,i,j,i,j-1,d[i][j-1][q-1]+a[i][j-1]),
		go(q,i,j,i,j+1,d[i][j+1][q-1]+a[i][j]),
		go(q,i,j,i-1,j,d[i-1][j][q-1]+b[i-1][j]),
		go(q,i,j,i+1,j,d[i+1][j][q-1]+b[i][j]);
	}
	rep(i,1,n) {
		rep(j,1,m) printf("%lld ",2*d[i][j][k]);
		puts("");
	}
	return 0;
}