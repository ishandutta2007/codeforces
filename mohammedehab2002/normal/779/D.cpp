#include <iostream>
#include <string.h>
using namespace std;
string a,b;
int p[200005];
bool r[200005];
bool check(int m)
{
	memset(r,0,sizeof(r));
	for (int i=0;i<m;i++)
	r[p[i]-1]=1;
	int cur=0;
	for (int i=0;i<a.size();i++)
	{
		if (cur<b.size() && !r[i] && a[i]==b[cur])
		cur++;
	}
	return (cur==b.size());
}
int main()
{
	cin >> a >> b;
	for (int i=0;i<a.size();i++)
	cin >> p[i];
	int st=0,en=a.size();
	while (st!=en)
	{
		int mid=(st+en+1)/2;
		if (check(mid))
		st=mid;
		else
		en=mid-1;
	}
	cout << st;
}