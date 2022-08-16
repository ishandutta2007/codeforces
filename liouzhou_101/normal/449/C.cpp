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

const int MaxN=100010;

int n;
int b[MaxN],u[MaxN];
vector<int> p;
vector<pii> ans;

void answer(int x,int y)
{
	ans.push_back(pii(x,y));
	u[x]=u[y]=1;
}

int main()
{
	cin>>n;
	for (int i=2;i<=n;++i)
		if (!b[i])
		{
			p.push_back(i);
			vector<int> q;
			for (int j=i;j<=n;j+=i)
			{
				b[j]=1;
				if (!u[j]) q.push_back(j);
			}
			if (i==2) continue;
			if (q.size()==1) continue;
			if (q.size()%2)
				q.erase(q.begin()+1,q.begin()+2);
			for (int i=0;i<q.size()/2;++i)
				answer(q[i*2],q[i*2+1]);
		}
	p.clear();
	for (int i=2;i<=n;i+=2)
		if (!u[i]) p.push_back(i);
	for (int i=0;i<p.size()/2;++i)
		answer(p[i*2],p[i*2+1]);
	cout<<ans.size()<<endl;
	for (auto x : ans)
		printf("%d %d\n",x.X,x.Y);
	return 0;
}