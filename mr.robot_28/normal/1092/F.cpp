#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
vector <long long> A;
vector <vector <int> > U;
vector <bool> used;
vector <long long> L, L1;
long long dfs(int v)
{
	used[v] = true;
	long long sum = 0, count = 0;
	for(int i = 0; i < U[v].size(); i++)
	{
		if(!used[U[v][i]])
		{
			long long u = dfs(U[v][i]);
			sum += L[U[v][i]];
			count += u;
		}
	}
	L[v] = sum + count;
	L1[v] = count;
	return count + A[v];
}
void dfs2(int v, int pred)
{
	//cout << v;
	used[v] = true;
	if(pred != -1)
	{
//	cout << v << " " << L1[pred]+ A[pred] - A[v] - L1[v] << endl;
		long long y = L[pred] - L[v] - A[v] - L1[v] + L1[pred]+ A[pred] - A[v] - L1[v];
		L[v] += y;
		L1[v] = L1[pred] + A[pred] - A[v];
	}
	for(int i = 0; i < U[v].size(); i++)
	{
		if(!used[U[v][i]])
		{
			dfs2(U[v][i], v);
		}
	}
}
int main()
{
	int n;
	cin >> n;
	used.resize(n);
	U.resize(n);
	A.resize(n);
	L.resize(n);
	L1.resize(n);
	for(int i =0; i < n; i++)
	{
		cin >> A[i];
	}
	int a, b;
	for(int i = 0; i < n - 1;i++)
	{
		cin >> a >> b;
		U[a - 1].push_back(b - 1);
		U[b - 1].push_back(a - 1);
	}
	long long o = dfs(0);
	for(int i = 0; i < n; i++)
	{
		//cout << L1[i] << " ";
		used[i] = false;
	}
	dfs2(0, -1);
	long long max = 0, imax = -1;
	for(int i = 0; i < n; i++)
	{
		if(L[i] > max)
		{
			max = L[i];
			imax = i;
		}
	//	cout << L[i] << " ";
	}
	cout << max;
	return 0;
}