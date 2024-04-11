#include<bits/stdc++.h> 

using namespace std;
vector <vector <int> > A; 
vector <bool> used;
vector <int> L;
void dfs(int v, int count)
{
	used[v] = true;
	L[v] = count;
	for(int i = 0; i < A[v].size(); i++)
	{
		if(!used[A[v][i]])
		{
			dfs(A[v][i], count);
		}
	}
}
void dfs1(int v)
{
	used[v] = true;
	for(int i = 0; i < A[v].size(); i++)
	{
		if(!used[A[v][i]])
		{
			cout << v + 1 << " " << A[v][i] + 1 << endl;
			dfs1(A[v][i]);
		}
	}
}
int main() { 
	int n, m, k;
	cin >> n >> m >> k;
	vector <int> P;
	A.resize(n);
	L.resize(n);
	used.resize(n, false);
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		if(x == 1)
		{
			P.push_back(y - 1);
		}
		else if(y == 1)
		{
			P.push_back(x - 1);
		}
		else
		{
			A[x - 1].push_back(y - 1);
			A[y - 1].push_back(x - 1);
		}
	}
	if(P.size() < k)
	{
		cout << "NO";
		return 0;
	}
	int count = 0;
	for(int i = 1; i < n; i++)
	{
		if(!used[i])
		{
			dfs(i, count);
			count++;
		}
	}
	if(count > k)
	{
		cout << "NO";
		return 0;
	}
	cout << "YES" << endl;
	vector <bool> F(n, false);
	for(int i = 0; i < n; i++)
	{
		used[i] = false;
	}
	int count1 = 0;
	vector <int> R;
	for(int i = 0; i < P.size(); i++)
	{
		//cout << L[P[i]] << endl;
		if(!F[L[P[i]]])
		{
			used[P[i]] = true;
			F[L[P[i]]] = true;
			count1++;
			R.push_back(P[i]);
			cout << 1 << " " << P[i] + 1 << endl;
		}
	}
	for(int i = 0; i < P.size(); i++){
		if(!used[P[i]] && count1 < k)
		{
			R.push_back(P[i]);
			count1 ++;
			used[P[i]] = true;
			cout << 1 << " " << P[i] + 1 << endl;
		}
	}
	for(int i = 0; i < R.size(); i++)
	{
		dfs1(R[i]);
	}
	return 0;
}