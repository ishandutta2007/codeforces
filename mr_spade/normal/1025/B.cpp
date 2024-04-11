#pragma GCC optimize("Ofast","inline")
#include<cstdio>
#include<cstring>
#include<ctime>
#include<algorithm>
#include<unordered_set>
using std::__gcd;
using std::random_shuffle;
using std::unordered_set;
const int N=2e5+5;
int n;
struct cell
{
	int a,b;
}c[N];
unordered_set<int> S[2];
signed main()
{
	srand(time(0));
	int x,g;
	bool flag;
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",&c[i].a,&c[i].b);
	random_shuffle(c+1,c+n+1);
	S[1].insert(c[1].a);S[1].insert(c[1].b);
	for(i=2;i<=n;i++)
	{
		S[i&1].clear();
		for(auto x:S[!(i&1)])
		{
			S[i&1].insert(__gcd(x,c[i].a));
			S[i&1].insert(__gcd(x,c[i].b));
		}
		if(i%1000==0)
		{
			flag=1;
			if(S[i&1].find(1)!=S[i&1].end())
				S[i&1].erase(1);
			if(!S[i&1].empty())
			{
				x=*S[i&1].begin();
				for(j=i+1;j<=n;j++)
				{
					if((g=__gcd(x,c[j].a))!=1)
						x=g;
					else if((g=__gcd(x,c[j].b))!=1)
						x=g;
					else
					{
						flag=0;
						break;
					}
				}
				if(flag)
				{
					printf("%d\n",x);
					return 0;
				}
			}
		}
	}
	for(auto x:S[n&1])
	{
		if(x!=1)
		{
			printf("%d\n",x);
			return 0;
		}
	}
	puts("-1");
	return 0;
}