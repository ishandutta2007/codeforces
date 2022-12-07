#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
multiset<int> S;
int n,a[510];
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x;i<=n*n;i++) scanf("%d",&x),S.insert(x);
	for(int i=1;i<=n;i++)
	{
		multiset<int>::iterator it=S.upper_bound(1000000001);
		it--;
		a[i]=(*it);
		for(int j=1;j<i;j++)
			S.erase(S.find(gcd(a[i],a[j]))),S.erase(S.find(gcd(a[i],a[j])));
		S.erase(S.find(a[i]));
	}
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	puts("");
	return 0;
}