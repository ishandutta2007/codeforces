#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

int main()
{
	int n;
	cin>>n;
	set<int> v,a,b,c;
	for (int i=1;i<=n;++i)
	{
		int x;
		cin>>x;
		if (x==0) v.insert(0);
		else if (x==100) v.insert(100);
		else if (x<10) a.insert(x);
		else if (x%10==0) b.insert(x);
		else c.insert(x);
	}
	int f=0;
	if (a.size())
	{
		v.insert(*a.begin());
		f=1;
	}
	if (b.size())
	{
		v.insert(*b.begin());
		f=1;
	}
	if (!f&&c.size())
		v.insert(*c.begin());
	cout<<v.size()<<endl;
	for (set<int>::iterator it=v.begin();it!=v.end();++it)
		printf("%d ",*it);
	return 0;
}