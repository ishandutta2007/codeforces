#include<bits/stdc++.h>
#define ll long long
#define mod 1000003
#define inv2 ((mod+1)>>1)
using namespace std;

ll n,m;
int ksm(int x,ll y){
	int t=1;
	for (; y; y>>=1,x=(ll)x*x%mod) if (y&1) t=(ll)t*x%mod; return t;
}
int calc(){
	int hh=ksm(2,n);
	if (hh<m) return 0;
	int i,sum=1;
	for (i=1; i<=m; i++,hh--) sum=(ll)sum*hh%mod;
	return sum;
}
int main(){
	scanf("%lld%lld",&n,&m);
	int len=0;
	ll aa=m-1;
	for (; aa; aa/=2)len++;
		if (len>n){puts("1 1"); return 0;}
	ll t=m-1,sum=n;
	for (; t; t/=2) sum+=t/2;
		int tot=ksm(ksm(2,n),m);
	int fenmu=(ll)tot*ksm(inv2,sum)%mod;
	int fenzi=calc();
	fenzi=(ll)fenzi*ksm(inv2,sum)%mod;
	printf("%d %d\n",(fenmu-fenzi+mod)%mod,fenmu);
	return 0;
}