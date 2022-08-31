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
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=100010;

int n;
string s;
int u[MaxN];

int main()
{
	getline(cin,s);
	n=s.size();
	for (int i=0;i<n;++i)
	{
		if (u[i]) continue;
		if (s[i]==' ') continue;
		putchar('<');
		if (s[i]=='"')
		{
			u[i]=1;
			for (int j=i+1;j<n;++j)
			{
				u[j]=1;
				if (s[j]=='"') break;
				putchar(s[j]);
			}
		}
		else
		{
			for (int j=i;j<n;++j)
			{
				u[j]=1;
				if (s[j]==' ') break;
				putchar(s[j]);
			}
		}
		puts(">");
	}
	return 0;
}