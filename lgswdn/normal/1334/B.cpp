#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100009;
int T,n,k,a[N];
signed main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1); reverse(a+1,a+n+1);
		int sum=0,ans=0;
		for(int i=1;i<=n;i++){
			sum+=a[i]; if(sum<i*k) break;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}