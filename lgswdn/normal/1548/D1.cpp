#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

int n,s[5][5],g[5][5],res,ans;

#define C(xa,ya,xb,yb) __gcd(abs(xa-xb),abs(ya-yb))

signed main() {
	n=read();
	rep(i,1,n) {int a=read()%4,b=read()%4; s[a][b]++;}
	rep(xa,0,3) rep(ya,0,3) rep(xb,0,3) rep(yb,0,3) rep(xc,0,3) rep(yc,0,3)
		if((C(xa,ya,xb,yb)+C(xb,yb,xc,yc)+C(xc,yc,xa,ya))%4==0)
			memcpy(g,s,sizeof(g)), res=1, res*=(g[xa][ya]--), res*=(g[xb][yb]--), res*=(g[xc][yc]--), ans+=res;
	printf("%lld\n",ans/6);
	return 0;
}