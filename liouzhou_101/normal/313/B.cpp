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
int n,T;
int a[100010];

int main()
{
	cin>>s;
	n=s.size();
	for (int i=1;i<s.size();++i)
		a[i]=a[i-1]+(s[i]==s[i-1]);
	cin>>T;
	while (T--)
	{
		int x,y;
		cin>>x>>y;
		cout<<a[y-1]-a[x-1]<<endl;
	}
	return 0;
}