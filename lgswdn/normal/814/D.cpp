#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=1009;
const double pi=acos(-1.);

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,x[N],y[N],r[N],deg[N];
double ans;

double dis(int a,int b) {
	return sqrt(1.*(x[a]-x[b])*(x[a]-x[b])+1.*(y[a]-y[b])*(y[a]-y[b]));
}
bool in(int a,int b) {
	return r[a]+r[b]>dis(a,b);
}
double area(int a) {
	//printf("%.8lf\n",pi*r[a]*r[a]);
	return pi*r[a]*r[a];
}

int main() {
	n=read();
	rep(i,1,n) x[i]=read(), y[i]=read(), r[i]=read(); 
	rep(i,1,n) rep(j,1,n) {
		if(i==j||r[i]<r[j]||(r[i]==r[j]&&i>j)) continue;
		if(in(i,j)) deg[j]++;
	}
	rep(i,1,n) {
		if(deg[i]==0||deg[i]%2==1) ans+=area(i);
		else ans-=area(i);
	}
	printf("%.8lf\n",ans);
	return 0;
}