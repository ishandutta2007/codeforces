#include<bits/stdc++.h>
using namespace std;
int t;
long long int k,n;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld",&n,&k);
		long long int res=1,kel=0;
		while(res<k){
			kel++;
			res=res+min(res,k);
		}
		if(res<n){
		if((n-res)%k==0)kel+=(n-res)/k;
		else kel+=(n-res)/k+1;
		}
		printf("%lld\n",kel);
	}
	return 0;
}