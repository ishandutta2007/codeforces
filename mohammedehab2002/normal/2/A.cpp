#include <iostream>
#include <vector>
#include <map>
#include <string.h>
using namespace std;
int main()
{
	vector < pair<string,int> > vec;
	map <string,int> points,win;
	map <string,int> :: iterator it;
	string winner;
	int i,t,maxi=-1000000,ans;
	cin >> t;
	vec.resize(t);
	for (i=0;i<t;i++)
	cin >> vec[i].first >> vec[i].second;
	for (i=0;i<t;i++)
	{
		ans=points[vec[i].first]+vec[i].second;
		points[vec[i].first]=ans;
	}
	for (it=points.begin();it!=points.end();it++)
	{
		ans=it->second;
		if (ans>maxi)
		maxi=ans;
	}
	for (i=0;i<t;i++)
	{
		ans=win[vec[i].first]+vec[i].second;
		win[vec[i].first]=ans;
		if (ans>=maxi && points[vec[i].first]==maxi)
		{
			winner=vec[i].first;
			break;
		}
	}
	cout << winner;
}