#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100009],cnt[10009];
signed main(){
	int T; cin>>T;
	while(T--){
		memset(cnt,0,sizeof(cnt));
		int n,x,sum=0; cin>>n>>x;
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]),cnt[a[i]%x]++,sum+=a[i]%x;
		if(cnt[0]==n){puts("-1");continue;}
		else if(sum%x!=0){printf("%lld\n",n);continue;}
		int l=1,r=n;
		for(;l<=n;l++) if(a[l]%x!=0) break;
		for(;r>=1;r--) if(a[r]%x!=0) break;
		printf("%lld\n",max(n-l,r-1));
	}
	return 0;
}