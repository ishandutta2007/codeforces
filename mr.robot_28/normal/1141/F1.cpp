#include<iostream>
#include<cmath>
#include<fstream>
#include<algorithm>
#include<map>
#include<iomanip>
#include<vector>
#include<stack>
using namespace std;
bool cmp(pair <int, int> a, pair <int, int> b)
{
	return a.second < b.second;
}
int main()
{
	#define int long long
	int n;
	cin >> n;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	vector <pair <int, int> > Max;
	map< int, vector <pair <int, int> > > W;
	for(int l = 0; l < n; l++)
	{
		int sum = 0;
		for(int r = l; r < n; r++)
		{
			sum += A[r];
			W[sum].push_back({l ,r});
		}
	}
	vector <pair <int, int> > Q;
	map <int, vector <pair <int, int> > > :: iterator it;
	for(it = W.begin(); it != W.end(); it++)
	{
		vector <pair <int, int> > E = it -> second;
		//cout << E.size() << endl;
		sort(E.begin(), E.end(), cmp);
		vector <pair <int, int> > Q;
		int r = -1e9;
		for(int i = 0; i < E.size(); i++)
		{
			if(E[i].first > r)
			{
				Q.push_back(E[i]);
				r = E[i].second;
			}
		}
		if(Q.size() > Max.size())
		{
			Max =Q;
		}
	}
	cout << Max.size() << endl;
	for(int i = 0; i < Max.size(); i++)
	{
		cout << Max[i].first + 1 << " " << Max[i].second + 1 << endl;
	}
	return 0;
}