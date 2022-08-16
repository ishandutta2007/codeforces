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
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxN=310;

int n;
int a[MaxN];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
	}
	string s;
	for (int T=1;T<=300;++T)
	{
		for (int i=1;i<=n;++i)
		{
			if (i>1) s+='R';
			if (a[i])
			{
				--a[i];
				s+='P';
			}
		}
		for (int i=1;i<n;++i)
			s+='L';
	}
	cout<<s<<endl;
	return 0;
}