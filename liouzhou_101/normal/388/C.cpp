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
int a[10010];
vector<int> p;
int x,y;

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		int s;
		cin>>s;
		for (int j=1;j<=s;++j)
		{
			cin>>a[j];
		}
		for (int j=1;j<=s/2;++j)
		{
			x+=a[j];
			y+=a[s-j+1];
		}
		if (s%2) p.push_back(a[s/2+1]);
	}
	sort(p.begin(),p.end());
	reverse(p.begin(),p.end());
	for (int i=0;i<p.size();++i)
	{
		if (i%2==0) x+=p[i]; else y+=p[i];
	}
	cout<<x<<" "<<y<<endl;
	return 0;
}