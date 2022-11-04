#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=2e5+9,mod=998244353;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int ksm(int a,int b) {
	if(b==0) return 1;
	else return ksm(a*a%mod,b/2)*(b%2?a:1)%mod;
}
int inv(int a) {return ksm(a,mod-2);}

int f[N];

signed main() {
	int n=read();
	rep(i,1,n) {
		f[i]=100*(f[i-1]+1)%mod*inv(read())%mod;
	}
	printf("%lld\n",f[n]);
	return 0;
}