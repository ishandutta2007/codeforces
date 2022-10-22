#include<bits/stdc++.h>
using namespace std;
const long long int N=200010;
long long int T,n,a[N],b[N];
long long int sum[N];
int main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			b[i]=a[i];
		}
		sort(b+1,b+n+1);
		for(long long int i=1;i<=n;i++){
			sum[i]=sum[i-1]+b[i];
		}
		long long int last=1;
		for(long long int i=n;i>=1;i--){
			if(sum[i-1]<b[i]){
				last=i;
				break;
			}
		}
		long long int su1m=0;
		for(long long int i=1;i<=n;i++){
			if(a[i]>=b[last]){
				su1m++;
			}
		}
		printf("%lld\n",su1m);
		for(long long int i=1;i<=n;i++){
			if(a[i]>=b[last]){
				printf("%lld ",i);
			}
		}
		printf("\n");
	}
	return 0;
}
/*
6
4
1 2 4 3
5
1 1 1 1 1
4
1 2 4 3
5
1 1 1 1 1
4
1 2 4 3
5
1 1 1 1 1
*/