#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;ll n,nn,t;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		for(nn=n,t=1;nn&1^1;nn>>=1,t<<=1);
		if(nn==1){printf("-1\n");continue;}
		if(nn<=2e9&&nn*(nn+1)/2<=n)printf("%lld\n",nn);
		if(t<=2e9&&t*(t<<1|1)<=n)printf("%lld\n",t<<1);
	}
	return 0;
}