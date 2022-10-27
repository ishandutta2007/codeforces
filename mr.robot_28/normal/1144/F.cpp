#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector <vector <pair <int, int> > > A;
vector <int> K;
vector <pair <int, int> > L;
vector <bool> used;
void dfs(int v, int type)
{
	used[v] = true;
	for(int i = 0; i < A[v].size(); i++)
	{
		if(used[A[v][i].first])
		{
			int z= A[v][i].second;
			if(type == 1)
			{
				if(L[z].first == v && K[z] == 0)
				{
					cout << "NO";
					exit(0);
				}
				else if(L[z].first == v)
				{
					K[z] = 1;
				}
				else if(L[z].second == v && K[z] == 1)
				{
					cout << "NO";
					exit(0);
				}
				else
				{
					K[z] = 0;
				}
			}
			else
			{
				if(L[z].first == v&& K[z] == 1)
				{
					cout << "NO";
					exit(0);
				}
				else if(L[z].first == v)
				{
					K[z] = 0;
				}
				else if(L[z].second == v && K[z] == 0)
				{
					cout << "NO";
					exit(0);
				}
				else
				{
					K[z] = 1;
				}
			}
		}
		else
		{
			int z = A[v][i].second;
			if(type == 1)
			{
				if(L[z].first == v)
				{
					K[z] = 1;
				}
				else
				{
					K[z] = 0;
				}
			}
			else
			{
				if(L[z].first == v)
				{
					K[z] = 0;
				}
				else
				{
					K[z] = 1;
				}
			}
			dfs(A[v][i].first, 1 - type);
		}
	}
}
int main(){
    int n, m;
    cin >> n >> m;
    A.resize(n);
    used.resize(n, false);
    K.resize(m, -1);
    for(int i = 0; i < m; i++)
    {
    	int x, y;
    	cin >> x >> y;
    	A[x - 1].push_back({y - 1, i});
    	A[y - 1].push_back({x - 1, i});
    	L.push_back({x - 1, y - 1});
	}
	dfs(0, 0);
	cout << "YES" << endl;
	for(int i = 0; i < m; i++)
	{
		cout << K[i];
	}
    return 0;
}