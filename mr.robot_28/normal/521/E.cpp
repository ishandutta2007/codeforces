#include<bits/stdc++.h>
using namespace std;
int n, m;
vector <vector <int> > g;
vector <int> h;
vector <int> p;
vector <int> used;
void print(vector <int> mass1, vector <int> mass2, vector <int> mass3)
{
	int st = mass1[0];
	int end = mass1[mass1.size() - 1];
	mass2.pop_back();
	mass3.pop_back();
	while(mass3.back() == mass2.back())
	{
		end = mass3.back();
		mass1.push_back(mass3.back());
		mass3.pop_back();
		mass2.pop_back();
	}
	reverse(mass1.begin(), mass1.end());
	reverse(mass2.begin(), mass2.end());
	reverse(mass3.begin(), mass3.end());
	mass2.pop_back();
	mass3.pop_back();
	while(mass2.back() == mass3.back())
	{
		st = mass2.back();
		mass1.push_back(mass2.back());
		mass2.pop_back();
		mass3.pop_back();
	}
	
	reverse(mass1.begin(), mass1.end());
	reverse(mass2.begin(), mass2.end());
	reverse(mass3.begin(), mass3.end());
	cout << "YES\n";
	cout << mass1.size() << " ";
	for(int i = 0; i < mass1.size(); i++)
	{
		cout << mass1[i] << " ";
	}
	cout << "\n" << mass2.size() + 2 << " ";
	cout << st << " ";
	for(int i = 0; i < mass2.size(); i++)
	{
		cout << mass2[i] << " ";
	}
	cout << end << " ";
	cout << "\n" << mass3.size() + 2<< " ";
	cout << st << " ";
	for(int i = 0; i < mass3.size(); i++)
	{
		cout << mass3[i] << " ";
	}
	cout << end << " ";
}
vector <int> stv, minv;
void dfs(int v, int pr = -1)
{
	used[v] = 1;
	int min1 = -1, st1, min2 = -1, st2;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to == pr)
		{
			continue;
		}
		if(!used[to])
		{
			h[to] = h[v] + 1;
			p[to] = v;
			dfs(to, v);
			if(minv[to] != -1 && h[minv[to]] < h[v])
			{
			if(min1 == -1 || h[min1] > h[minv[to]])
			{
				min2 = min1;
				st2 = st1;
				st1 = stv[to];
				min1 = minv[to];
			}
			else if(min2 == -1  || h[min2] > h[minv[to]])
			{
				min2 = minv[to];
				st2 = stv[to];
			}
			}
		}
		else if(used[v] == 1 && h[to] < h[v])
		{
			if(min1 == -1 || h[to] < h[min1])
			{
				min2 = min1;
				st2 = st1;
				st1 = v;
				min1 = to;
			}
			else if(min2 == -1  || h[to] < h[min2])
			{
				min2 = to;
				st2 = v;
			}
		}
	}
	minv[v] = min1;
	stv[v] = st1; 
	used[v] = 2;
	if(min1 != -1 && min2 != -1)
	{
		vector <int> mass1, mass2, mass3;
		mass1.push_back(v + 1);
		mass1.push_back(pr + 1);
		int t = pr;
		while(t != min1)
		{
			mass2.push_back(t + 1);
			t = p[t];
		}
		mass2.push_back(t + 1);
		t = st1;
		while(t != v){
			mass2.push_back(t + 1);
			t = p[t];
		}
		mass2.push_back(v + 1);
		reverse(mass2.begin(), mass2.end());
		t = pr;
		while(t != min2)
		{
			mass3.push_back(t + 1);
			t = p[t];
		}
		mass3.push_back(t + 1);
		t = st2;
		while(t != v){
			mass3.push_back(t + 1);
			t = p[t];
		}
		mass3.push_back(v + 1);
		reverse(mass3.begin(), mass3.end());
		print(mass1, mass2, mass3);
		exit(0);
	}
}
signed main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	cin >> n >> m;
	g.resize(n);
	minv.resize(n, -1);
	p.resize(n);
	stv.resize(n, -1);
	h.resize(n);
	used.resize(n);
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i = 0; i < n; i++)
	{
		if(!used[i])
		{
			dfs(i);
		}
	}
	cout << "NO";
    return 0;
}