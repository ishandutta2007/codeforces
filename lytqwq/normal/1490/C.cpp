#include<bits/stdc++.h>
using namespace std;
long long int T,x;
int main(){
	scanf("%lld",&T);
	while(T--){
		int did=0;
		scanf("%lld",&x);
		for(long long int i=1;i<=10000;i++){
			if(i*i*i>=x)break;
			long long int ne=x-i*i*i;
			long long int l=1,r=10000,mid=0,ok=0;
			while(l<=r){
				mid=(l+r)>>1;
				if(mid*mid*mid==ne){
					ok=1;
					break;
				}
				else if(mid*mid*mid>ne){
					r=mid-1;
				}
				else{
					l=mid+1;
				}
			}
			if(ok){
				did=1;
				printf("YES\n");
				break;
			}
		}
		if(!did)printf("NO\n");
	}
	return 0;
}