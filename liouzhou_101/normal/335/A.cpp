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
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

string s;
int n;
map<char,int> F,G;

bool check(int x)
{
	int s=0;
	for (int i='a';i<='z';++i)
	{
		if (!F[i]) continue;
		s+=G[i]=(F[i]-1)/x+1;
	}
	if (s<=n)
	{
		cout<<x<<endl;
		for (int i='a';i<='z';++i)
			for (int j=0;j<G[i];++j)
				putchar(i);
		for (int i=s+1;i<=n;++i)
			putchar('a');
		return true;
	}
	return false;
}

int main()
{
	cin>>s>>n;
	for (int i=0;i<s.size();++i)
		F[s[i]]++;
	for (int i=1;i<=1000;++i)
		if (check(i)) return 0;
	puts("-1");
	return 0;
}