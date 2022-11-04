#include<bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int b,int a){
	if(b==0) return a;
	else return gcd(a%b,b);
}
signed main(){
	int T; scanf("%lld",&T);
	while(T--){
		int a,b,k; scanf("%lld%lld%lld",&a,&b,&k);
		if(a>b) swap(a,b);
		int g=gcd(a,b); a/=g,b/=g;
		int p=(k-1)*a+1;
		if(p>=b) puts("OBEY");
		else puts("REBEL");
	}
	return 0;
}