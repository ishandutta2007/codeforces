#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<queue>
#include<list>
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxN=400010;

int a[MaxN],b[MaxN];

int main()
{
	string s,t;
	cin>>s>>t;
	reverse(s.begin(),s.end());
	reverse(t.begin(),t.end());
	for (int i=1;i<=100000;++i)
		s+='0';
	for (int i=1;i<=100000;++i)
		t+='0';
	while (s.size()<t.size()) s+='0';
	while (t.size()<s.size()) t+='0';
	int n=s.size();
	for (int i=0;i<n;++i)
		a[i]=s[i]-'0';
	for (int i=0;i<n;++i)
		b[i]=t[i]-'0';
	for (int i=n-1;i>=2;--i)
	{
		if (a[i-1]&&a[i-2])
		{
			a[i]=1;
			a[i-1]=a[i-2]=0;
			i=min(i+2,n-1)+1;
		}
	}
	for (int i=n-1;i>=2;--i)
	{
		if (b[i-1]&&b[i-2])
		{
			b[i]=1;
			b[i-1]=b[i-2]=0;
			i=min(i+2,n-1)+1;
		}
	}
	for (int i=n-1;i>=0;--i)
	{
		if (a[i]<b[i])
		{
			puts("<");
			return 0;
		}
		if (a[i]>b[i])
		{
			puts(">");
			return 0;
		}
	}
	puts("=");
	return 0;
}