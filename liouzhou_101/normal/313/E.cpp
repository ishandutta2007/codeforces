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

const int MaxN=100010;

int n,m;
int a[MaxN],b[MaxN];
vector<int> qa,qb,ans;

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	for (int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		b[x]++;
	}
	for (int i=0;i<m;++i)
	{
		while (a[m-i-1]--)
			qa.push_back(m-i-1);
		while (b[i]--)
			qb.push_back(i);
		while (qa.size()&&qb.size())
		{
			if (*qa.rbegin()+*qb.rbegin()>=m) break;
			ans.push_back(*qa.rbegin()+*qb.rbegin());
			qa.pop_back();
			qb.pop_back();
		}
	}
	for (int i=0;i<qa.size();++i)
		ans.push_back((qa[i]+qb[qa.size()-i-1])%m);
	sort(ans.begin(),ans.end());
	reverse(ans.begin(),ans.end());
	for (int i=0;i<n;++i)
		printf("%d ",ans[i]);
	return 0;
}