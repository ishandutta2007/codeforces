#include<cstdio>
#include<cstring>
#include<set>
using std::multiset;
const int N=1e6+5;
int n,m,cnt0;
char s[N];
multiset<int> S1,S2;
signed main()
{
	int cur,cnt;
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		m=strlen(s+1);
		cur=0;cnt=0;
		for(j=1;j<=m;j++)
			if(s[j]=='(')
				cur++;
			else
			{
				if(!cur)
					cnt++;
				else
					cur--;
			}
		if(cur&&cnt)
			continue;
		if(cur==0&&cnt==0)
			cnt0++;
		else if(cur==0)
			S2.insert(cnt);
		else
			S1.insert(cur);
	}
	int ans=cnt0/2;
	for(auto x:S1)
		if(S2.find(x)!=S2.end())
		{
			S2.erase(S2.find(x));
			ans++;
		}
	printf("%d\n",ans);
	return 0;
}