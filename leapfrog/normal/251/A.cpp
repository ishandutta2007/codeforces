#include<bits/stdc++.h>
using namespace std;
int n,d,x[100005];long long ans;
inline long long C2(long long x) {return x%2?(x-1)/2*x:x/2*(x-1);}
int main()
{
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++) scanf("%d",x+i);
	sort(x+1,x+n+1),ans=0;
	for(int l=1,r=1;l<=n;l++)
	{
		while(r+1<=n&&x[r+1]-x[l]<=d) r++;
		ans=ans+C2(r-l);
	}
	return printf("%lld\n",ans),0;
}