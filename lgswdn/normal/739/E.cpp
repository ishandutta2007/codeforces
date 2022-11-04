#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef vector<int> vec;
typedef pair<int,double> pr;
typedef long double ld;
const ld eps=1e-12;
const int N=2009;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,a,b;
ld p[N],u[N];

pr bsb(ld ca) {
	ld l=0,r=1; pr res=pr(0,0);
	while(l+eps<=r) {
		ld cb=(l+r)/2;
		int ua=0,ub=0; ld sum=0;
		rep(i,1,n) {
			long double x=p[i]-ca, y=u[i]-cb, z=p[i]+u[i]-p[i]*u[i]-ca-cb;
			if(x<eps&&y<eps&&z<eps) continue;
			if(y>=x&&y>=z) sum+=y, ub++;
			else if(x>=y&&x>=z) sum+=x, ua++;
			else sum+=z, ua++, ub++;
		}
		res.second=sum+a*ca+b*cb, res.first=ua;
		if(ub<b) r=cb;
		else if(ub==b) break;
		else l=cb;
	}
	return res;
}
ld bsa() {
	ld l=0,r=1,res=0;
	while(l+eps<=r) {
		ld mid=(l+r)/2;
		pr rp=bsb(mid);
		int use=rp.first; ld ans=rp.second;
		res=ans;
		if(use<a) r=mid;
		else if(use==a) break;
		else l=mid;
	}
	return res;
}

int main() {
	n=read(), a=read(), b=read();
	rep(i,1,n) scanf("%Lf",&p[i]);
	rep(i,1,n) scanf("%Lf",&u[i]);
	printf("%.3Lf\n",bsa());
	return 0;
}