#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000005],sum=0;
int ans=1e18;
void update(int x){
	int res=0,now=0;
	for(int i=1;i<=n;i++){
		now+=a[i];
		now%=x;
		res+=min(now,x-now);
	}
	ans=min(ans,res);
}
signed main(){
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
		sum+=a[i];
	}
	for(int i=2;i*i<=sum;i++){
		if(sum%i==0){
			update(i);
			while(sum%i==0)sum/=i;
		}
	}
	if(sum!=1)update(sum);
	cout<<(ans==1e18?-1ll:ans)<<endl;
	return 0;
}