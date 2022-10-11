#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
string s[1005];
map<int,int> comp;
int p[1005],ans[2][1005];
int c(int a,char m)
{
	return count(s[a].begin(),s[a].end(),m);
}
bool cmp(int a,int b)
{
	if (c(a,'>')==c(b,'>'))
	return c(a,'<')>c(b,'<');
	return c(a,'>')<c(b,'>');
}
int main()
{
	int n,m;
	cin >> n >> m;
	for (int i=0;i<n;i++)
	cin >> s[i];
	for (int i=0;i<n;i++)
	p[i]=i;
	sort(p,p+n,cmp);
	ans[0][p[0]]=2;
	for (int i=1;i<n;i++)
	{
		ans[0][p[i]]=ans[0][p[i-1]];
		if (s[p[i]]!=s[p[i-1]])
		ans[0][p[i]]+=2;
	}
	for (int i=0;i<n;i++)
	comp[ans[0][i]];
	for (int i=0;i<m;i++)
	{
		int l=1,r=1e9;
		for (int j=0;j<n;j++)
		{
			if (s[j][i]=='>')
			r=min(r,ans[0][j]-1);
			else if (s[j][i]=='=')
			{
				r=min(r,ans[0][j]);
				l=max(l,ans[0][j]);
			}
			else
			l=max(l,ans[0][j]+1);
		}
		if (r<l)
		{
			printf("No");
			return 0;
		}
		ans[1][i]=l;
		if (l%2 && r>l)
		ans[1][i]++;
		comp[ans[1][i]];
	}
	int cur=0;
	for (auto &p:comp)
	p.second=++cur;
	printf("Yes\n");
	for (int i=0;i<n;i++)
	printf("%d%c",comp[ans[0][i]]," \n"[i==n-1]);
	for (int i=0;i<m;i++)
	printf("%d ",comp[ans[1][i]]);
}