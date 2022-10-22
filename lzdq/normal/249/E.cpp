#include<cstdio>
#include<algorithm>
using namespace std;
typedef __int128 ll;
const int MAXN=1e5+5;
const ll mod=10000000000;
ll s1(int n){
	return (ll)(n)*(n+1)/2;
}
ll s2(int n){
	return (ll)(n)*(n+1)*(n*2+1)/6;
}
ll Left(int n,int m){
	return s2(n)*m-s1(m-1)*n;
}
ll Right(int n,int m){
	return n*s2(m-1)+s1(n)*m;
}
ll Calc(int n,int m){
	if(!n||!m) return 0;
	ll k=min(n,m);
	ll res=(k*k)*(k*k+1)/2;
	if(k<n) res+=Left(n,m)-Left(m,m);
	if(k<m) res+=Right(n,m)-Right(n,n);
	return res;
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		ll ans=Calc(x2,y2)-Calc(x2,y1-1)-Calc(x1-1,y2)+Calc(x1-1,y1-1);
		long long res=ans%mod;
		if(ans==res) printf("%lld\n",res);
		else printf("...%010lld\n",res);
	}
	return 0;
}