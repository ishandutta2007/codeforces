#include<bits/stdc++.h>
using namespace std;
int P,n,k;long long r=0;map<int,int>v;
int main()
{
	scanf("%d%d%d",&n,&P,&k);
	for(int i=1,x;i<=n;i++) scanf("%d",&x),v[(1ll*x*x%P*x%P*x%P-1ll*k*x%P+P)%P]++;
	for(auto i:v) r=r+1ll*i.second*(i.second-1)/2;
	return printf("%lld\n",r),0;
}