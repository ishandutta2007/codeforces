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

int n,k;

int main()
{
	cin>>n>>k;
	if (n<k)
	{
		puts("-1");
		return 0;
	}
	if (k==1)
	{
		if (n==1)
			puts("a");
		else
			puts("-1");
		return 0;
	}
	string s;
	for (int i=1;i<=n;++i)
	{
		if (i%2) s+='a'; else s+='b';
		if (n-s.size()==k-2)
		{
			for (int j=2;j<k;++j)
				s+='a'+j;
			break;
		}
	}
	cout<<s<<endl;
	return 0;
}