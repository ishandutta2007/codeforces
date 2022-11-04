#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=509;
int n,a[N],ans;
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				ans=max(ans,a[i]|a[j]|a[k]);
	printf("%lld",ans);
	return 0;
}