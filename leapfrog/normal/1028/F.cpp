//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
struct pt
{
	int x,y;char operator<(pt b) const {return x^b.x?x<b.x:y<b.y;}
	inline pt operator+(pt b) {return(pt){x+b.x,y+b.y};}
	inline pt operator-(pt b) {return(pt){x-b.x,y-b.y};}
	inline pt fac() {int g=__gcd(x,y);return(pt){x/g,y/g};}
	inline void fc() {int g=__gcd(x,y);x/=g,y/=g;}
};
map<pt,int>mp;
map<ll,set<pt> >vc;
int main()
{
	int Ca,tot=0;for(read(Ca);Ca--;)
	{
		int fg,x,y;read(fg,x,y);
		if(fg==3) {printf("%d\n",tot-mp[((pt){x,y}).fac()]);continue;}
		if(fg==1)
		{
			tot++;set<pt>&r=vc[1ll*x*x+1ll*y*y];
			for(auto w:r) mp[(w+(pt){x,y}).fac()]+=2;
			mp[((pt){x,y}).fac()]++,r.insert((pt){x,y});
		}
		else
		{
			tot--;set<pt>&r=vc[1ll*x*x+1ll*y*y];
			r.erase((pt){x,y}),mp[((pt){x,y}).fac()]--;
			for(auto w:r) mp[(w+(pt){x,y}).fac()]-=2;
		}
	}return 0;
}