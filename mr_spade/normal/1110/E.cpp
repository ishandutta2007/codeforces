#include<cstdio>
#include<set>
using std::multiset;
const int N=1e5+5;
int n;
int a[N],b[N];
multiset<int> S;
signed main()
{
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=2;i<=n;i++)
		S.insert(a[i]-a[i-1]);
	for(i=1;i<=n;i++)
		scanf("%d",&b[i]);
	if(b[1]!=a[1])
		return puts("No"),0;
	for(i=2;i<=n;i++)
		if(S.find(b[i]-b[i-1])==S.end())
			return puts("No"),0;
		else
			S.erase(S.find(b[i]-b[i-1]));
	puts("Yes");
}