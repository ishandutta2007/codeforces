#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define x first
#define y second
typedef long long ll;
pair<int,int> arr[100005];
bool col(pair<ll,ll> a,pair<ll,ll> b,pair<ll,ll> c)
{
	return ((a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y))==0);
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d%d",&arr[i].x,&arr[i].y);
	vector<pair<int,int> > v;
	v.push_back(arr[0]);
	v.push_back(arr[1]);
	for (int i=2;i<n;i++)
	{
		if (!col(arr[0],arr[1],arr[i]))
		{
			v.push_back(arr[i]);
			break;
		}
	}
	if (v.size()==2)
	{
		printf("YES");
		return 0;
	}
	sort(v.begin(),v.end());
	do {
		vector<pair<int,int> > no;
		for (int i=0;i<n;i++)
		{
			if (!col(v[0],v[1],arr[i]) && arr[i]!=v[2])
			no.push_back(arr[i]);
		}
		bool ok=1;
		for (int i=1;i<no.size();i++)
		ok&=col(v[2],no[0],no[i]);
		if (ok)
		{
			printf("YES");
			return 0;
		}
	} while (next_permutation(v.begin(),v.end()));
	printf("NO");
}