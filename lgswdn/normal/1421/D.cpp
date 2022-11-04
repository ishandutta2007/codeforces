#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
using namespace std;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int t,x,y,c[9];

signed main() {
	t=read();
	while(t--) {
		x=read(), y=read();
		//printf("%lld %lld\n",x,y);
		rep(i,1,6) c[i]=read();
		rep(i,1,6) c[i]=min(c[i],c[i==1 ? 6 : i-1]+c[i==6 ? 1 : i+1]);
		if(x>0&&y>0&&x>=y) printf("%lld\n",y*c[1]+(x-y)*c[6]);
		else if(x>0&&y>0&&x<y) printf("%lld\n",x*c[1]+(y-x)*c[2]);
		else if(x<0&&y<0&&x>=y) printf("%lld\n",-x*c[4]+(x-y)*c[5]);
		else if(x<0&&y<0&&x<y) printf("%lld\n",-y*c[4]+(y-x)*c[3]);
		else if(x<=0&&y>=0) printf("%lld\n",-x*c[3]+y*c[2]);
		else if(x>=0&&y<=0) printf("%lld\n",-y*c[5]+x*c[6]);
	}
	return 0;
}
//