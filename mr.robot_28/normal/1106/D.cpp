#include<bits/stdc++.h> 
using namespace std;
int main () 
{ 
	int n, m;
	cin >> n >> m;
	vector <vector <int> > A(n);
	for(int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		A[a - 1].push_back(b - 1);
		A[b - 1].push_back(a - 1);
	}
	set	<int> W;
	vector <bool> used(n);
	int count = 1;
	vector <int> F;
	W.insert(0);
	while(F.size() != n)
	{
		set <int> :: iterator it;
		it = W.begin();
		int v = *it;
		F.push_back(v);
		used[v] = true;
		W.erase(v);
		for(int i = 0; i < A[v].size(); i++)
		{
			if(!used[A[v][i]])
			{
				W.insert(A[v][i]);
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		cout << F[i] + 1 << " ";
	}
	return 0;
}