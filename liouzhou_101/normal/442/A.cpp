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
#include<unordered_set>
#include<unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

int n;
string s[110];
int u[110];
char c[10]={'R','G','B','Y','W','1','2','3','4','5'};

int main()
{
	cin>>n;
	for (int i=0;i<n;++i)
		cin>>s[i];
	int ans=10;
	for (int i=0;i<1<<10;++i)
	{
		for (int k=0;k<n;++k)
		{
			u[k]=0;
			for (int j=0;j<10;++j)
			{
				if (i&1<<j)
				if (s[k][0]==c[j]||s[k][1]==c[j]) u[k]|=1<<j;
			}
		}
		int flag=0;
		for (int i=0;i<n;++i)
			for (int j=i+1;j<n;++j)
				if ((s[i]==s[j])^(u[i]==u[j])) flag=1;
		if (!flag)
		{
			ans=min(ans,(int)bitset<10>(i).count());
		}
	}
	cout<<ans<<endl;
	return 0;
}