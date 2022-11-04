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

const int N=1009;
int n;
double p[N][N],d[N],g[N],q[N];
bool vst[N];

void dijkstra() {
	d[n]=0; rep(i,1,n-1) d[i]=2e18;
	rep(t,1,n-1) {
		int x=1; rep(i,1,n) if(d[i]<d[x]&&!vst[i]) x=i;
		if(x==1) return; vst[x]=1;
		rep(y,1,n) if(!vst[y]) {
			g[y]+=(d[x]+1)*p[y][x]*q[y];
			q[y]*=(1-p[y][x]);
		}
		rep(i,1,n) d[i]=(g[i]+q[i])/(1-q[i]);
	}
}

signed main() {
	n=read();
	rep(i,1,n) q[i]=1;
	rep(i,1,n) rep(j,1,n) p[i][j]=read()/100.;
	dijkstra();
	printf("%.7lf\n",d[1]);
	return 0;
}