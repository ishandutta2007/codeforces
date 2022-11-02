#include<bits/stdc++.h>
using namespace std;
int n,ans=0,c[100005];
int main()
{
	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout),scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",c+i);
	sort(c+1,c+n+1);
	for(int l=1,r=1;r<=n;l++)
	{
		for(;r<=n;r++) if(c[r]>c[l]*2) break;
		ans=max(ans,r-l);
	}
	return printf("%d\n",n-ans),0;
}