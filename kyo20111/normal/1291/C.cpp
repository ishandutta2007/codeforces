#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, m, k, a[3535];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&n,&m,&k);
		for(int i=1;i<=n;i++) scanf("%d",a+i);

		if(k >= m-1){
			int mx = 0;
			for(int i=1;i<=m;i++) mx = max({mx, a[i], a[n-i+1]});
			printf("%d\n",mx);
			continue;
		}

		int ans = 0;
		for(int i=0;i<=k;i++){
			int l = i + 1, r = n - (k - i);
			int mn = 1e9;
			for(int j=0;j<=m-k-1;j++){
				mn = min(mn, max(a[l+j], a[r-((m-k-1)-j)]));
			}
			ans = max(ans, mn);
		}
		printf("%d\n",ans);
	}
}