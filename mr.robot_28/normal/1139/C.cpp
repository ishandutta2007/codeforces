#include <iostream>
#include<cmath>
#include<iomanip>
#include<vector>
using namespace std;
const int E = 1e9 + 7;
vector <vector <int> > A;
vector <int > d;
vector <bool> used;
void dfs(int v)
{
	used[v] = true;
	for(int i =0; i < A[v].size(); i++)
	{
		if(!used[A[v][i]])
		{
			dfs(A[v][i]);
			d[v] += d[A[v][i]];
		}
	}
	d[v] += 1;
}
long long power(int n, int k)
{
	if(k == 1)
	{
		return n;
	}
	else if(k % 2 == 0)
	{
		long long y = power(n, k / 2);
		return (y * y) % E;
	}
	else
	{
		long long y = power(n, k / 2);
		return ((y * n) % E) * y % E;
	}
}
int main() {
	#define int long long
	int n, k;
	cin >> n >> k;
	A.resize(n);
	d.resize(n, 0);
	used.resize(n, false);
	for(int i = 0; i < n - 1; i++)
	{
		int v, u, x;
		cin >> v >> u >> x;
		if(x != 1)
		{
			A[v - 1].push_back(u - 1);
			A[u - 1].push_back(v - 1);
		}
	}
	long long sum = power(n, k);
	//cout << power(n, k);
	for(int i = 0; i <n; i++)
	{
		if(!used[i])
		{
			dfs(i);
			int y = d[i];
			sum = (sum - power(y, k) + E) % E;
		}
	}
	cout << sum;
	return 0;
}