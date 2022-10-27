#pragma gcc optimize("O3");
#pragma gcc target("SSE4");
#include <bits/stdc++.h> 
using namespace std;
int n, to, i, j;
vector <string> A;
vector <int> qm;
void rec(int v, vector <int> l)
{
	if(l.size() >= 3)
	{
	vector <int> in, out;
	for(int i = 0; i < l.size(); i++)
	{
		if(A[v][l[i]] == '1')
		{
			out.push_back(l[i]);
		}
		else if(v != l[i])
		{
			in.push_back(l[i]);
		}
	}
	for(int i = 0; i < in.size(); i++)
	{
		for(int j = 0; j < out.size(); j++)
		{
			if(A[out[j]][in[i]] == '1')
			{
				cout << out[j] +1 << " " << in[i] + 1 << " " << v + 1;
				exit(0);
			}
		}
	}
	if(in.size() >= 3)
	{
		rec(in[rand() % in.size()], in);
	}
	if(out.size() >= 3)
	{
		rec(out[rand() % out.size()], out);
	}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int r, p = 0;
	cin >> n;
	string t;
	vector <int> k(n + 1);
	A.resize(n);
	qm.resize(n);
	for(i = 0; i < n; i++)
	{
		cin >> A[i];
		qm[i] = i;
	}
	if(p == n)
	{
		cout << -1;
		return 0;
	}
	
	rec(rand() % n, qm);
	cout << -1;
	return 0;
}