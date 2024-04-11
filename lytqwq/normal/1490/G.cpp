#include<bits/stdc++.h>
using namespace std;
const long long int N=200010;
long long int t,n,m,a[N],x[N];
vector<long long int > ovo;
int main(){
	scanf("%lld",&t);
	while(t--){
		ovo.clear();
		scanf("%lld%lld",&n,&m);
		long long int sum=0,maxn=-1e9-1;
		for(long long int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			sum+=a[i];
			if(sum>maxn){
				maxn=sum;
			}
			ovo.push_back(maxn);
		}
		for(long long int i=1;i<=m;i++){
			scanf("%lld",&x[i]);
			if(x[i]>maxn){
				if(sum>=1){
					long long int ju=ceil((x[i]-maxn)*1.0/sum);
					x[i]-=ju*sum;
					long long int ans=lower_bound(ovo.begin(),ovo.end(),x[i])-ovo.begin();
					printf("%lld ",ans+ju*n);
					
				}
				else{
					printf("-1 ");
				}
			}
			else{
				long long int ans=lower_bound(ovo.begin(),ovo.end(),x[i])-ovo.begin();
				printf("%lld ",ans);
			}
		}
		printf("\n");
		
	}
	return 0;
}