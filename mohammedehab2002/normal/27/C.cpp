#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
int sign(int x)
{
	return (x<0? -1:1);
}
int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i=0;i<n;i++)
	cin >> arr[i];
	int i=1,x;
	while (i!=n && arr[i]==arr[i-1])
	i++;
	int d=arr[i]-arr[i-1];
	for (x=i+1;x<n;x++)
	{
		if (arr[x]!=arr[x-1] && sign(arr[x]-arr[x-1])!=sign(d))
		break;
	}
	if (x>=n)
	cout << 0;
	else
	{
		v.push_back(x);
		for (int j=x-1;v.size()!=3;j--)
		{
			if (arr[j]!=arr[v.back()])
			v.push_back(j);
		}
		cout << 3 << endl << v[2]+1 << ' ' << v[1]+1 << ' ' << v[0]+1;
	}
}