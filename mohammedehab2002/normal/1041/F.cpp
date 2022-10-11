#include <iostream>
#include <map>
using namespace std;
map<int,int> cnt;
int a[100005],b[100005];
int main()
{
	int n,m,y;
	scanf("%d%d",&n,&y);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	scanf("%d%d",&m,&y);
	for (int i=0;i<m;i++)
	{
		scanf("%d",&b[i]);
		cnt[b[i]]++;
	}
	int ans=0;
	for (auto p:cnt)
	ans=max(ans,p.second);
	for (int i=1;i<=1e9;i*=2)
	{
		cnt.clear();
		for (int j=0;j<n;j++)
		cnt[a[j]%(2*i)]++;
		for (int j=0;j<m;j++)
		cnt[(b[j]+i)%(2*i)]++;
		for (auto p:cnt)
		ans=max(ans,p.second);
	}
	printf("%d",ans);
}