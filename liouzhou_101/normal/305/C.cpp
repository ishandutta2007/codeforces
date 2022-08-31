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

int n;
multiset<int> s;
vector<int> p;

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		s.insert(x);
	}
	p.push_back(-1);
	while (s.size()>1)
	{
		multiset<int>::iterator x=s.begin();
		int vx=*x;
		s.erase(x);
		multiset<int>::iterator y=s.begin();
		int vy=*y;
		s.erase(y);
		if (vx==vy)
		{
			s.insert(vx+1);
			continue;
		}
		s.insert(vy);
		p.push_back(vx);
	}
	p.push_back(*s.begin());
	int ans=0;
	for (int i=1;i<p.size();++i)
		ans+=p[i]-p[i-1]-1;
	cout<<ans<<endl;
	return 0;
}