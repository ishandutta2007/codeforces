#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
	int n,i;
	cin >> n;
	pair <string,string> p[n];
	int arr[n];
	for (i=0;i<n;i++)
	{
		cin >> p[i].first >> p[i].second;
		if (p[i].first.compare(p[i].second)==1)
		swap (p[i].first,p[i].second);
	}
	for (i=0;i<n;i++)
	cin >> arr[i];
	string tmp=p[arr[0]-1].first;
	for (i=1;i<n;i++)
	{
		if (p[arr[i]-1].second.compare(tmp)==-1)
		{
			cout << "NO";
			return 0;
		}
		if (p[arr[i]-1].first.compare(tmp)==1)
		tmp=p[arr[i]-1].first;
		else
		tmp=p[arr[i]-1].second;
	}
	cout << "YES";
}