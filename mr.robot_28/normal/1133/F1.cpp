#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
vector <bool> used;
vector <pair <int,  int> > K;
vector <vector <int> > A;
int main()
{
	int n, m;
	cin >> n >> m;
	A.resize(n);
	used.resize(n, 0);
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		A[x - 1].push_back(y - 1);
		A[y - 1].push_back(x - 1);
	}
	int min = 0, imin = 0;
	for(int i = 0; i < n; i++)
	{
		if(A[i].size() > min)
		{
			min = A[i].size();
			imin = i;
		}
	}
	queue <int> Q;
	Q.push(imin);
	used[imin] = true;
	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		for(int i = 0; i < A[v].size(); i++)
		{
			if(!used[A[v][i]])
			{
				used[A[v][i]] = true;
				Q.push(A[v][i]);
				K.push_back({v, A[v][i]});
			}
		}
	}
	for(int i = 0; i < K.size(); i++)
	{
		cout << K[i].first + 1 << " " << K[i].second + 1 << endl;
	}
	return 0;
}