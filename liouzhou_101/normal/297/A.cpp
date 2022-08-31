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

const int MaxN=1010;

int n,m;
string a,b;
int sa,sb;

int main()
{
	cin>>a>>b;
	n=a.size();
	m=b.size();
	for (int i=0;i<n;++i) sa+=a[i]-'0';
	for (int i=0;i<m;++i) sb+=b[i]-'0';
	if (sa%2) ++sa;
	puts(sa>=sb?"YES":"NO");
	return 0;
}