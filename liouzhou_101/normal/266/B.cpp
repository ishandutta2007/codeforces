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
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=100010;

int d[MaxN];

int main()
{
	int n,t;
	string s;
	cin>>n>>t>>s;
	while (t--)
	{
		for (int i=0;i<n;++i)
			d[i]=0;
		for (int i=1;i<n;++i)
		{
			if (s[i]=='G'&&s[i-1]=='B')
			{
				d[i]=-1;
				d[i-1]=1;
			}
		}
		string t=s;
		for (int i=0;i<n;++i)
			t[i]=s[i+d[i]];
		s=t;
	}
	cout<<s<<endl;
	return 0;
}