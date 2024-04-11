#pragma gcc optimize("O3");
#pragma gcc target("SSE4");
#include <bits/stdc++.h> 
using namespace std;
int main()
{
	int n, m, a, b;
	cin >> n >> m;
	vector <set <int> > col(n);
	for(int i = 0; i < n; i++)
	{
		col[i].insert(i);
	}
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b;
		a--;
		b--;
		col[a].insert(a * n + b);
		col[b].insert(a * n + b);
	}
	for(int i = 0; i < n; i++)
	{
		cout << col[i].size() << endl;
		set <int> :: iterator it;
		for(it = col[i].begin(); it != col[i].end(); it++)
		{
			cout << i + 1<< " " << *it + 1 << endl;
		}
	}
	return 0;
}