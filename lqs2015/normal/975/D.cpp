#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;
map<long long,long long> ks;
map<pair<long long,long long>,long long> kk;
long long n,ans;
long long a,b,x,vx,vy,y;
int main()
{
	scanf("%I64d%I64d%I64d",&n,&a,&b);
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d%I64d%I64d",&x,&vx,&vy);
		y=a*x+b;
		ks[vy-vx*a]++;
		kk[make_pair(vx,vy)]++;
	}
	for (map<long long,long long>::iterator it=ks.begin();it!=ks.end();it++)
	{
		ans+=it->second*(it->second-1);
	}
	for (map<pair<long long,long long>,long long>::iterator it=kk.begin();it!=kk.end();it++)
	{
		ans-=it->second*(it->second-1);
	}
	printf("%I64d\n",ans);
	return 0;
}