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
string s;

int main()
{
	cin>>n>>s;
	for (int i=0;i<n;++i)
	{
		if (s[i]!='.')
		{
			cout<<i+1<<" ";
			if (s[i]=='L')
			{
				cout<<i<<endl;
				return 0;
			}
			for (int j=i+1;j<n;++j)
				if (s[j]!='R')
				{
					if (s[j]=='.') cout<<j+1<<endl;
					else cout<<j<<endl;
					return 0;
				}
		}
	}
	return 0;
}