#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using std::sort;
using std::upper_bound;
using std::unique;
using std::vector;
int n,k;
char s[1000000];
vector<char> V;
signed main()
{
	register int i;
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	for(i=0;i<n;i++)
		V.push_back(s[i]);
	sort(V.begin(),V.end());
	int m=unique(V.begin(),V.end())-V.begin();
	while(V.size()>m)
		V.pop_back();
	if(n>=k)
	{
		int now=k-1;
		while(s[now]==V[m-1])
			now--;
		for(i=0;i<now;i++)
			putchar(s[i]);
		putchar(*upper_bound(V.begin(),V.end(),s[now]));
		for(i=now+1;i<k;i++)
			putchar(V[0]);
		putchar('\n');
	}
	else
	{
		printf("%s",s);
		for(i=n;i<k;i++)
			putchar(V[0]);
		putchar('\n');
	}
	return 0;
}