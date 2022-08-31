#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

int n;
vector<int> a,b,c;

void print(vector<int> &a)
{
	cout<<a.size();
	for (int i=0;i<a.size();++i)
		cout<<" "<<a[i];
	cout<<endl;
}

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		int x;
		cin>>x;
		if (x<0) a.push_back(x);
		if (x>0) b.push_back(x);
		if (!x) c.push_back(x);
	}
	if (b.empty())
	{
		b.push_back(*a.rbegin());
		a.pop_back();
		b.push_back(*a.rbegin());
		a.pop_back();
	}
	if (a.size()%2==0)
	{
		c.push_back(*a.rbegin());
		a.pop_back();
	}
	print(a);
	print(b);
	print(c);
	return 0;
}