#include<iostream>
#include<cmath>
#include<map>
#include<fstream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
vector <int> pred, rang;
vector <int> d;
int pred1(int v)
{
	if (pred[v] == v) return v;
	else return pred[v] = pred1(pred[v]);
}
void unite(int a, int b)
{
	a = pred1(a);
	b = pred1(b);
	if(rang[a] < rang[b])
	{
		swap(a, b);
	}
	pred[b] = a;
	if(rang[a] == rang[b])
	{
		rang[a]++;
	}
}
main()
{
	#define int long long
	int n, m;
	cin >> n >> m;
	pred.resize(n + 1);
	rang.resize(n + 1);
	d.resize(n + 1);
	for(int i = 1; i <= n; i++)
	{
		pred[i] = i;
	}
	for(int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		vector <int> A(k);
		for(int j =0; j < k; j++)
		{
			cin >> A[j];
			if(j != 0)
			{
				unite(A[j], A[j - 1]);
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		d[pred1(i)]++;
	}
	for(int i = 1; i <= n; i++)
	{
		d[i] = d[pred1(i)];
		cout << d[i] << " ";
	}
    return 0;
}