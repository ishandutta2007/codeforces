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
string s;
int u[300010];

int main()
{
	cin>>n>>k>>s;
	u[0]=1;
	for (int i=0;i<n;++i)
	{
		if (s[i]=='#') continue;
		if (!u[i]) continue;
		for (int j=i+1;j<n;++j)
		{
			if (j-i>k) break;
			if (s[j]=='.')
			{
				u[j]=1;
				break;
			}
		}
	}
	puts(u[n-1]?"YES":"NO");
	return 0;
}