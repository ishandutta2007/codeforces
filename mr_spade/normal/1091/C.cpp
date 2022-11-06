#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
using std::sort;
using std::vector;
int n;
vector<int> V;
inline void check(int x)
{
	V.push_back((n/x-1)*(n/x)/2*x+n/x);
	return;
}
signed main()
{
	register int i;
	scanf("%lld",&n);
	for(i=1;i*i<=n;i++)
		if(n%i==0)
		{
			check(i);
			if(n/i!=i)
				check(n/i);
		}
	sort(V.begin(),V.end());
	for(auto x:V)
		printf("%lld ",x);
	putchar('\n');
	return 0;
}