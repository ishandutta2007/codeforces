#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=1e6+9;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}

int n,mx,a[N],p[N],q[N],s[2][N];

int lb(int x) {return x&(-x);}
void add(int *s,int x,int y) {for(;x<=mx;x+=lb(x)) s[x]+=y;}
int qry(int *s,int x,int ret=0) {x=min(x,mx);for(;x;x-=lb(x)) ret+=s[x]; return ret;}

signed main() {
	n=read();
	rep(i,1,n) a[i]=read(), mx=max(mx,a[i]);
	int sum=0;
	rep(i,1,n) {
		sum+=a[i]; add(s[0],a[i],1);
		p[i]=p[i-1]+a[i]*(i-1)-qry(s[1],a[i]), q[i]=q[i-1]+sum;
		for(int j=a[i];j<=mx;j+=a[i]) {
			q[i]-=j*(qry(s[0],j+a[i]-1)-qry(s[0],j-1));
			add(s[1],j,j), add(s[1],j+a[i],-j);
		}
		printf("%lld ",p[i]+q[i]);
	}
	return 0;
}