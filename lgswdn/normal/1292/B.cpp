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
typedef bitset<509> bset;
typedef pair<bset,bset> v2;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=60,lim=2e16;
int x0,y0,ax,ay,bx,by,n,xs,ys,t,x[N],y[N],ans;

int dis(int i,int j) {
	return abs(x[i]-x[j])+abs(y[i]-y[j]);
}

signed main() {
	x0=read(), y0=read(), ax=read(), ay=read(), bx=read(), by=read();
	xs=read(), ys=read(), t=read();
	x[1]=x0, y[1]=y0; x[0]=xs, y[0]=ys;
	int n=1;
	while(x[n]<=lim&&y[n]<=lim) x[n+1]=ax*x[n]+bx, y[n+1]=ay*y[n]+by, n++;
	rep(s,1,n-1) {
		int r=t;
		r-=dis(0,s);
		int res=(r>=0);
		if(r<0) {ans=max(ans,res); continue;} 
		per(i,s,2) {
			r-=dis(i-1,i);
			if(r<0) break;
			res++;
		}
		r-=dis(s+1,1);
		if(r<0) {ans=max(ans,res); continue;}
		res++;
		rep(i,s+1,n-1) {
			r-=dis(i+1,i);
			if(r<0) break;
			res++;
		}
		ans=max(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}