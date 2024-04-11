#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int find(int x,int arr[],int size)
{
	int i;
	for (i=0;i<size;i++)
	{
		if (arr[i]==x)
		return i;
	}
}
int main()
{
	vector <pair<int,int> > v;
	pair <int,int> p;
	int n,i,x,test;
	cin >> n;
	int arr[n];
	for (i=0;i<n;i++)
	cin >> arr[i];
	for (i=0;i<n;i++)
	{
		test=i;
		for (x=i+1;x<n;x++)
		{
			if (arr[test]>arr[x])
			test=x;
		}
		if (i!=test)
		{
			p.first=i;
			p.second=test;
			v.push_back(p);
			swap (arr[i],arr[test]);
		}
	}
	cout << v.size() << endl;
	for (i=0;i<v.size();i++)
	cout << v[i].first << " " << v[i].second << endl;
}