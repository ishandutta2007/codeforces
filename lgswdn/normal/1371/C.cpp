#include<bits/stdc++.h>
using namespace std;
int main(){
	int T; cin>>T;
	while(T--) {
		long long a,b,n,m;
		scanf("%lld%lld%lld%lld",&a,&b,&n,&m);
		if(a+b<n+m){puts("No");continue;}
		long long g=min(a,b);
		if(g>=m) puts("Yes");
		else puts("No");
	}
	return 0;
}