#include <iostream>
#include <map>
using namespace std;
int arr[200005],siz[200005],col[200005],c[200005];
map<int,int> m[200005];
int find(int x)
{
	if (arr[x]!=x)
	arr[x]=find(arr[x]);
	return arr[x];
}
void Union(int x,int y)
{
	x=find(x);
	y=find(y);
	if (x==y)
	return;
	arr[y]=x;
	siz[x]+=siz[y];
	siz[y]=0;
}
int main()
{
	int n,r,k;
	cin >> n >> r >> k;
	for (int i=1;i<=n;i++)
	{
		arr[i]=i;
		siz[i]=1;
		cin >> col[i];
	}
	while (r--)
	{
		int a,b;
		cin >> a >> b;
		Union(a,b);
	}
	for (int i=1;i<=n;i++)
	{
		int x=find(i);
		m[x][col[i]]++;
		c[x]=max(c[x],m[x][col[i]]);
	}
	long long ans=0;
	for (int i=1;i<=n;i++)
	ans+=siz[i]-c[i];
	cout << ans;
}