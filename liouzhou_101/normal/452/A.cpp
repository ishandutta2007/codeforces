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

string t[]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int n;
string s;

int main()
{
	cin>>n>>s;
	for (int i=0;i<8;++i)
	{
		if (t[i].size()!=n) continue;
		int cnt=0;
		for (int j=0;j<n;++j)
		{
			if (s[j]=='.') continue;
			if (t[i][j]!=s[j]) cnt=1;
		}
		if (!cnt)
		{
			cout<<t[i]<<endl;
			break;
		}
	}
	return 0;
}