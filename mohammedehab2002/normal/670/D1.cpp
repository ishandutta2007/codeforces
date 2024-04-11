#include <iostream>
#include <set>
using namespace std;
set <pair<pair<int,int>,int> > s;
int main()
{
	int n,k;
	cin >> n >> k;
	int arr[n],arr2[n];
	for (int i=0;i<n;i++)
	cin >> arr[i];
	for (int i=0;i<n;i++)
	{
		cin >> arr2[i];
		s.insert(make_pair(make_pair(arr2[i]/arr[i],arr[i]-arr2[i]%arr[i]),i));
	}
	while (k)
	{
		set <pair<pair<int,int>,int> > :: iterator it=s.begin();
		int ans=(*s.begin()).first.second;
		if (k-ans<0)
		k=0;
		else
		{
			pair <pair<int,int>,int> ins=(*s.begin());
			k-=ins.first.second;
			ins.first.first++;
			ins.first.second=arr[ins.second];
			s.erase(s.begin());
			s.insert(ins);
		}
		
	}
	cout << (*s.begin()).first.first;
}