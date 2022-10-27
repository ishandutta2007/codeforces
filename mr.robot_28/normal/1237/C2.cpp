#include <bits/stdc++.h>
using namespace std;
#define int long long
int dist(pair <pair <int, int>, int> a, pair <pair <int, int>, int> b)
{
	return (a.first.first - b.first.first) * (a.first.first - b.first.first) + (a.first.second - b.first.second) * (a.first.second - b.first.second) + (a.second - b.second) * (a.second - b.second);
}
signed main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <pair <pair <int, int>, pair <int,int> > > A(n);
	for(int i = 0; i < n; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		A[i] = {{x, y}, {z, i}};
	}
	sort(A.begin(), A.end());
	vector <pair <pair <int, int>, pair <int, int> > > B;
	for(int i = 0; i < n; i++)
	{
		int j = i + 1;
		while(j < n && A[j].first.first == A[i].first.first && A[j].first.second == A[i].first.second)
		{
			j++;
		}
		int t = j - 1;
		for(; t >= i + 1; t -= 2)
		{
			cout << A[t].second.second + 1 << " " << A[t - 1].second.second + 1 << "\n";
		}
		if(t == i)
		{
			B.push_back(A[i]);
		}
		i = j - 1;
	}
	vector <pair <pair <int, int>, pair <int,int> > > C;
	for(int i =0; i < B.size(); i++)
	{
		int j = i + 1;
		while(j < B.size() && B[j].first.first == B[i].first.first)
		{
			j++;
		}
		int t = j - 1;
		for(; t >= i + 1; t-= 2)
		{
			cout << B[t].second.second + 1 << " " << B[t - 1].second.second + 1 << "\n";
		}
		if(t == i)
		{
			C.push_back(B[i]);
		}
		i = j - 1;
	}
	for(int i = 0; i < C.size(); i+=2)
	{
		cout << C[i].second.second + 1 << " " << C[i + 1].second.second + 1 << "\n";
	}
  	return 0;
}