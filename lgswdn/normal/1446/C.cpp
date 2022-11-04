#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=200009;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,a[N];
int calc(int l,int r,int k) {
	if(l==r||k==-1) return 1;
	int x=r;
	while(x>=l&&(a[x]&(1<<k))) x--;
	if(x==l-1||x==r) return calc(l,r,k-1);
	else {
		int ret=1+max(calc(l,x,k-1),calc(x+1,r,k-1));
		//cout<<l<<" "<<r<<" "<<ret<<endl;
		return ret;
	}
}

int main() {
	n=read();
	rep(i,1,n) a[i]=read();
	sort(a+1,a+n+1);
	cout<<n-calc(1,n,30);
	return 0;
}