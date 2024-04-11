#include<bits/stdc++.h>
using namespace std;
const int N=20;
int t,n,k,a[N];
long long int Qp(int y){
	long long int res=1;
	while(y--){
		res=res*10;
	}
	return res;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		k++;
		long long int ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			if(i>=2){
				int res=a[i]-a[i-1];
				long long int kel=Qp(res)-1;
				if(k<kel){
					printf("%lld\n",ans+k*Qp(a[i-1]));
					break;
				}
				else{
					k-=kel;
					ans+=kel*Qp(a[i-1]);
				}
			}
			if(i==n){
				ans+=k*Qp(a[i]);
				printf("%lld\n",ans);
			}
		}
		
	}
	return 0;
}