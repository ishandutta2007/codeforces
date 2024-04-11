#include <iostream>
#include <string.h>
#include <set>
using namespace std;
int b[200005][2],arr[200005];
set<int> s;
bool ex[200005];
int main()
{
	int n;
	scanf("%d",&n);
	memset(b,-1,sizeof(b));
	for (int i=1;i<=n;i++)
	s.insert(i);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		b[a][1]=i;
		if (b[a][0]==-1)
		b[a][0]=i;
		arr[i]=a;
		if (s.find(a)!=s.end())
		s.erase(s.find(a));
	}
	int ans=0;
	for (int i=0;i<n;i++)
	{
		if (!s.size())
		continue;
		if (b[arr[i]][0]==b[arr[i]][1])
		continue;
		if (ex[arr[i]])
		{
			arr[i]=*s.begin();
			s.erase(s.begin());
			ans++;
		}
		else if (b[arr[i]][1]==i)
		continue;
		else if (*s.begin()<arr[i])
		{
			arr[i]=*s.begin();
			s.erase(s.begin());
			ans++;
		}
		else
		ex[arr[i]]=1;
	}
	printf("%d\n",ans);
	for (int i=0;i<n;i++)
	printf("%d ",arr[i]);
}