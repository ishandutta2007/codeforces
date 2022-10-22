#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans;
int a[maxn];
long long s[maxn],t[maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),s[i]=i==1? 0:(s[i-1]+(a[i]<a[i-1]? (a[i-1]-a[i]):0));
	for(int i=n-1;i>=1;i--)
		t[i]=t[i+1]+(a[i+1]>a[i]? (a[i+1]-a[i]):0);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(x<=y)
			printf("%lld\n",s[y]-s[x]);
		else printf("%lld\n",t[y]-t[x]);
	}
	return 0;
}