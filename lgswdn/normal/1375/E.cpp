#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=1e3+9;
typedef pair<int,int> pii;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,a[N],q[N];
pii b[N];

void swp(int x,int y) {
	q[a[x]]=y, q[a[y]]=x, swap(a[x],a[y]);
	printf("%d %d\n",x,y);
}

int main() {
	n=read();
	rep(i,1,n) a[i]=read(), b[i]=make_pair(a[i],i);
	sort(b+1,b+n+1);
	rep(i,1,n) a[b[i].second]=i, q[i]=b[i].second;
	int cnt=0;
	rep(i,1,n) rep(j,i+1,n) cnt+=(a[j]<a[i]);
	printf("%d\n",cnt);
	per(i,n,1) {
		rep(j,a[i]+1,i) swp(q[j],i);
	}
	return 0;
}