#include<cstdio>
#include<set>
#define int long long
using std::set;
int n;
set<int> S;
inline int calc()
{
	int res;
	register int i,j,k;
	for(i=0;i<=n;i++)
		for(j=i;j<=n;j++)
			for(k=j;k<=n;k++)
				S.insert(i+(j-i)*5+(k-j)*10+(n-k)*50);
	res=S.size();
	S.clear();
	return res;
}
signed main()
{
	scanf("%lld",&n);
	if(n<=10)
		printf("%lld\n",calc());
	else
		printf("%lld\n",292+49*(n-11));
	return 0;
}