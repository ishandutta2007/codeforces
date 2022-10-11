#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
	int n,m,i,x,a,arr[105],maxi=0,ind;
	cin >> n >> m;
	vector <int> v[m];
	memset (arr,0,sizeof(arr));
	for (i=0;i<m;i++)
	{
		for (x=0;x<n;x++)
		{
			cin >> a;
			v[i].push_back(a);
		}
	}
	for (i=0;i<m;i++)
	{
		vector <int> :: iterator it=max_element(v[i].begin(),v[i].end());
		int ans=find(v[i].begin(),v[i].end(),*it)-v[i].begin();
		arr[ans]++;
	}
	for (i=0;i<105;i++)
	{
		if (arr[i]>maxi)
		{
			maxi=arr[i];
			ind=i;
		}
	}
	cout << ind+1;
}