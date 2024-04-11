#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e5 + 5;
int n,sum[N],x,ans=0;
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&x),sum[i]=sum[i-1]+x;
	for(int i=1;i<n;i++)
		if(sum[i]==sum[n]-sum[i])ans++;
	printf("%d",ans);
	return 0;
}