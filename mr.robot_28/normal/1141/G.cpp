#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;
map<pair <int, int> , int> W;
vector <int> L;
vector <bool> used;
vector <vector <int> > A;
void dfs(int v, int cnt, int d)
{
	used[v] = true;
	for(int i = 0; i < A[v].size(); i++)
	{
		if(!used[A[v][i]])
		{
		L[W[{v, A[v][i]}]] = cnt;
		cnt = (cnt + 1) % (d + 1);
		if(cnt == 0)
		{
			cnt = 1;
		}
		dfs(A[v][i], cnt, d);
		}
	}
}
int main()
{
	int n, k;
	cin >> n >> k;
	vector <int> B(n, 0);
	L.resize(n - 1);
	A.resize(n);
	for(int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >>x >> y;
		B[x - 1]++;
		B[y - 1]++;
		W[{x - 1, y - 1}] = i;
		W[{y - 1, x - 1}] = i;
		A[x - 1].push_back(y - 1);
		A[y - 1].push_back(x - 1);
	}
	used.resize(n, false);
	int imin = 0;
	for(int i = 0; i < n; i++)
	{
		if(B[i] == 1)
		{
			imin = i;
			break;
		}
	}
	sort(B.begin(), B.end());
	cout << B[n - k - 1] << endl;
	dfs(imin, 1, B[n - k - 1]);
	for(int i  = 0; i <n - 1; i++)
	{
		cout << L[i] << " ";
	}
	return 0;
}