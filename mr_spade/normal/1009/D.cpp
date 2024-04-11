#include<cstdio>
#include<cstring>
#include<vector>
#define int long long
using std::pair;
using std::make_pair;
using std::vector;
const int N=1e5+5;
inline int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int n,m;
vector<pair<int,int> > V;
signed main()
{
	register int i,j;
	scanf("%lld%lld",&n,&m);
	if(m<n-1)
		return puts("Impossible"),0;
	m-=n-1;
	for(i=2;i<=n;i++)
		V.push_back(make_pair(1,i));
	if(!m)
		goto end;
	for(i=2;i<=n;i++)
		for(j=2;j<i;j++)
			if(gcd(i,j)==1)
			{
				V.push_back(make_pair(j,i));
				if(!--m)
					goto end;
			}
	return puts("Impossible"),0;
	end:;
	puts("Possible");
	for(i=0;i<(int)V.size();i++)
		printf("%lld %lld\n",V[i].first,V[i].second);
	return 0;
}