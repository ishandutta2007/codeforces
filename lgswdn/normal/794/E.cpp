#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=1e6+9;
typedef pair<int,int>pii;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}
int n,a[N],f[N],g[N],h[N],mx;

int main() {
	n=read();
	rep(i,1,n) a[i]=read(), mx=max(mx,a[i]);
	rep(i,1,n-1) {
		int p=min(i,n-i);
		h[p]=max(h[p],max(a[i],a[i+1]));
	}
	rep(i,2,n-1) {
		int p=min(i-1,n-i);
		g[p]=max(g[p],max(min(a[i-1],a[i]),min(a[i],a[i+1])));
	}
	per(i,n,1) {
		if(i%2==0) f[i]=max(f[i+2],h[i/2]);
		else f[i]=max(f[i+2],g[i/2]);
		printf("%d ",i==1?mx:f[i]);
	} puts("");
	return 0;
}