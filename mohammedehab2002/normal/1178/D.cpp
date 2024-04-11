#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define MX 2000
vector<pair<int,int> > ans;
map<pair<int,int>,bool> con;
int deg[1005];
bool p[MX+5];
void add(int a,int b,bool no)
{
	if (deg[a]==3 || deg[b]==3 || con[{a,b}] || (no && !p[ans.size()]))
	return;
	deg[a]++;
	deg[b]++;
	ans.push_back({a,b});
	con[{a,b}]=1;
	con[{b,a}]=1;
}
int main()
{
	for (int i=2;i<=MX;i++)
	{
		for (int j=2*i;j<=MX;j+=i)
		p[j]=1;
	}
	int n;
	scanf("%d",&n);
	if (n==7)
	{
		printf("7\n");
		for (int i=1;i<=n;i++)
		printf("%d %d\n",i,i%n+1);
		return 0;
	}
	for (int i=1;i<=n-2;i+=3)
	{
		add(i,i+1,0);
		add(i+1,i+2,0);
		add(i+2,i,0);
	}
	if (n%3==1)
	{
		add(1,n,0);
		add(2,n,0);
	}
	if (n%3==2)
	{
		add(n-1,n,0);
		add(n-1,1,0);
		add(n,2,0);
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		add(i,j,1);
	}
	printf("%d\n",ans.size());
	for (auto p:ans)
	printf("%d %d\n",p.first,p.second);
}