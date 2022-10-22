#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int b[maxn],a[maxn];
string s;
signed main(){
	scanf("%lld",&T);
	while(T--){
		flg=1;
		scanf("%lld%lld",&n,&m);
		for(int i=n-m+1;i<=n;i++)
			scanf("%lld",&b[i]);
		for(int i=n-m+2;i<=n;i++){
			a[i]=b[i]-b[i-1];
			if(i>n-m+2)
				flg&=(a[i]>=a[i-1]);
		}
		int k=b[n-m+1],lim=m==1? 1e12:a[n-m+2];
		if(flg==1&&lim*(n-m+1)>=k)
			puts("YES");
		else puts("NO");
	}
	return 0;
}