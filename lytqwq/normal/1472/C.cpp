#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int t,n,a[N];
long long int f[N],ans;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		ans=0;
		for(int i=n;i>=1;i--){
			if(i+a[i]<=n)
			f[i]=f[i+a[i]]+a[i];
			else
			f[i]=a[i];
			ans=max(ans,f[i]);
		}
		printf("%lld\n",ans);
	}
}