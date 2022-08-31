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

int main()
{
	string s;
	cin>>s;
	if (s.size()==1)
	{
		puts("Yes");
		return 0;
	}
	int flag=0;
	for (int i=0;i+1<s.size();++i)
		if (s[i]=='Q')
			flag=1;
	if (!flag)
	{
		puts("Yes");
		return 0;
	}
	flag=0;
	for (int i=0;i+1<s.size();++i)
		if (s[i]=='H')
			flag=1;
	if (!flag)
	{
		puts("Yes");
		return 0;
	}
	for (int i=0;i<s.size();++i)
		if (s[i]=='H')
		{
			if (i<s.size()/2)
			{
				if (s.substr(0,i+1)==s.substr(s.size()-i-1)&&s[s.size()-i-2]=='H')
					puts("Yes");
				else
					puts("No");
			}
			else
				puts("No");
			return 0;
		}
	puts("Yes");
	return 0;
}