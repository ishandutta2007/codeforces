#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn],b[maxn],c[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),b[i]=a[i],c[i]=a[i];
		if(n==1){
			puts("0");
			continue;
		}
		sort(b+1,b+n),sort(c+2,c+1+n);
		int ans=max(a[n]-b[1],c[n]-a[1]);
		for(int i=1;i<=n;i++)
			ans=max(ans,a[i]-a[i%n+1]);
		printf("%d\n",ans);
	}
	return 0;
}