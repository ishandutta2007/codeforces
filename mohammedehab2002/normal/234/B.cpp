#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	vector <int> s;
	int n,k,i;
	cin >> n >> k;
	pair <int,int> arr[n];
	for (i=0;i<n;i++)
	{
		cin >> arr[i].first;
		arr[i].second=i+1;
	}
	sort (arr,arr+n);
	cout << arr[n-k].first << endl;
	for (i=n-1;i>n-k-1;i--)
	s.push_back(arr[i].second);
	sort (s.begin(),s.end());
	for (i=0;i<s.size();i++)
	cout << s[i] << " ";
}