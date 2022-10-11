#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include <set>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int get(int m,char c)
{
	printf("%c %d\n",c,m);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
int gcd(int a,int b)
{
	if (!a)
	return b;
	if (!b)
	return a;
	return __gcd(a,b);
}
int main()
{
	int n;
	scanf("%d",&n);
	int st=0,en=1e9;
	while (st!=en)
	{
		int mid=(st+en)/2;
		if (get(mid,'>'))
		st=mid+1;
		else
		en=mid;
	}
	set<int> s;
	while (s.size()!=min(n,30))
	s.insert(uniform_int_distribution<int>(1,n)(rng));
	int ans=0;
	for (int i:s)
	ans=gcd(ans,st-get(i,'?'));
	printf("! %d %d",st-(n-1)*ans,ans);
}