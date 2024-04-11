#include<cstdio>
#include<cstring>
#include<vector>
#include<bitset>
using std::vector;
using std::bitset;
const int N(505),M(10005);
int n,m,ans;
char word[N],nn[N];
vector<int>a;
bitset<30>book,yes,now;
signed main()
{
	int i,j;
	vector<int>::iterator k;
	for(i=1;i<=26;i++)
		yes[i]=1;
	scanf("%d",&n);
	scanf("%s",word+1);
	for(i=1;i<=n;i++)
		if(word[i]=='*')
			a.push_back(i);
		else
			book[word[i]-'a'+1]=1;
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		int flag(0);
		for(j=1;j<=26;j++)
			now[j]=0;
		scanf("%s",nn+1);
		for(j=1;j<=n;j++)
			if(word[j]!='*'&&nn[j]!=word[j])
			{
				flag=1;
				break;
			}
		if(flag)
			continue;
		for(k=a.begin();k!=a.end();k++)
			if(!book[nn[*k]-'a'+1])
				now[nn[*k]-'a'+1]=1;
			else
			{
				flag=1;
				break;
			}
		if(flag)
			continue;
		for(j=1;j<=26;j++)
			yes[j]=yes[j]&now[j];
	}
	for(i=1;i<=26;i++)
		if(yes[i])
			ans++;
	printf("%d\n",ans);
	return 0;
}