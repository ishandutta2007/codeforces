#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	vector <int> room,v;
	vector <int> :: iterator it;
	int n,i,a,ans,maxi=0;
	cin >> n;
	pair <char,int> arr[n];
	for (i=0;i<n;i++)
	{
		cin >> arr[i].first >> arr[i].second;
		if (arr[i].first=='+')
		v.push_back(arr[i].second);
		else
		{
			it=find(v.begin(),v.end(),arr[i].second);
			if (it==v.end())
			room.push_back(arr[i].second);
		}
	}
	ans=room.size();
	maxi=ans;
	for (i=0;i<n;i++)
	{
		if (arr[i].first=='+')
		{
			ans++;
			room.push_back(arr[i].second);
		}
		else
		{
			it=find(room.begin(),room.end(),arr[i].second);
			if (it!=room.end())
			{
				ans--;
				room.erase(it);
			}
		}
		if (ans>maxi)
		maxi=ans;
	}
	cout << maxi;
}