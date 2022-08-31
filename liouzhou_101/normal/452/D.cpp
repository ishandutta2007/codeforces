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

const int MaxN=30010000;

short int a1[MaxN],a2[MaxN],a3[MaxN];
int k,n1,n2,n3,t1,t2,t3;

int main()
{
	cin>>k>>n1>>n2>>n3>>t1>>t2>>t3;
	for (int i=0;i<=30000000;++i)
	{
		if (i)
		{
			a1[i]+=a1[i-1];
			a2[i]+=a2[i-1];
			a3[i]+=a3[i-1];
		}
		while (a1[i]<n1&&a2[i]<n2&&a3[i]<n3)
		{
			if (!--k)
			{
				cout<<i+t1+t2+t3<<endl;
				return 0;
			}
			++a1[i];
			--a1[i+t1];
			++a2[i];
			--a2[i+t2];
			++a3[i];
			--a3[i+t3];
		}
	}
	return 0;
}