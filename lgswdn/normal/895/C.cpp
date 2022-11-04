#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=1e5+9,mod=1e9+7;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,a,lb[N],sz,p[20]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};

void insert(int x) {
	per(i,18,0) if((1<<i)&x) {
		if(!lb[i]) {lb[i]=x; sz++; return;}
		x^=lb[i];
	}
}

int main() {
	n=read();
	rep(i,1,n) {
		a=read();
		int s=0;
		rep(i,0,18) {
			int c=0;
			while(a%p[i]==0) a/=p[i],c^=1;
			s+=c*(1<<i);
		}
		insert(s);
	}
	int ans=1;
	rep(i,sz+1,n) ans=1ll*ans*2%mod;
	printf("%d\n",ans-1);
	return 0;
}