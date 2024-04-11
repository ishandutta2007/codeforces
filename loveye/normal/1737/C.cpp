#include<bits/stdc++.h>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(file) freopen(file".in","r",stdin)
#define fileout(file) freopen(file".out","w",stdout)

struct Point {
	int x,y;
	void Read() {
		x=read(),y=read();
	}
	bool operator == (const Point &o) {return x==o.x||y==o.y;}
} a,b,c,d;
int n;
int main() {
	int T=read();
	while(T--) {
		n=read();
		a.Read(); b.Read();
		c.Read(); d.Read();
		if(b==a&&b==c) swap(a,b);
		if(c==a&&c==b) swap(a,c);
		if((a.x==1||a.x==n)&&(a.y==1||a.y==n))
			puts(a==d?"YES":"NO");
		else {
			if((d.x+d.y&1)==(a.x+a.y&1))
				puts((a.x&1)==(d.x&1)?"YES":"NO");
			else puts("YES");
		}
	}
	return 0;
}
int read() {
	static int x,c,f; x=0,f=1;
	do c=getchar(),(c=='-'&&(f=-1)); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}