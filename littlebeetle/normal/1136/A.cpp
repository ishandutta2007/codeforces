#include<cstdio>
const int N=10002;
int n,l[N],r[N],i,k,ans;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",l+i,r+i);
	scanf("%d",&k);
	for(i=1;i<=n;i++)
		if(k<=r[i])
			ans++;
	printf("%d",ans);
}