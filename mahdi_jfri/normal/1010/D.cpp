#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e6 + 20;

int l[maxn] , r[maxn];
string type[maxn];

bool to[maxn] , from[maxn][2];

void dfsdown(int v)
{
	if(type[v] == "IN")
		return;

	dfsdown(l[v]);
	if(type[v] != "NOT")
		dfsdown(r[v]);

	if(type[v] == "NOT")
		to[v] = !to[l[v]];

	if(type[v] == "XOR")
		to[v] = to[l[v]] ^ to[r[v]];

	if(type[v] == "OR")
		to[v] = to[l[v]] | to[r[v]];

	if(type[v] == "AND")
		to[v] = to[l[v]] & to[r[v]];
}

void dfsup(int v)
{
	if(v == 1)
	{
		from[v][0] = 0;
		from[v][1] = 1;
	}

	if(type[v] == "IN")
		return;

	if(type[v] == "NOT")
		for(int i = 0; i < 2; i++)
			from[l[v]][i] = from[v][!i];

	if(type[v] == "XOR")
	{
		for(int i = 0; i < 2; i++)
			from[l[v]][i] = from[v][to[r[v]]^i];
		for(int i = 0; i < 2; i++)
			from[r[v]][i] = from[v][to[l[v]]^i];
	}

	if(type[v] == "OR")
	{
		for(int i = 0; i < 2; i++)
			from[l[v]][i] = from[v][to[r[v]]|i];
		for(int i = 0; i < 2; i++)
			from[r[v]][i] = from[v][to[l[v]]|i];
	}

	if(type[v] == "AND")
	{
		for(int i = 0; i < 2; i++)
			from[l[v]][i] = from[v][to[r[v]]&i];
		for(int i = 0; i < 2; i++)
			from[r[v]][i] = from[v][to[l[v]]&i];
	}

	dfsup(l[v]);
	if(type[v] != "NOT")
		dfsup(r[v]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		cin >> type[i];

		if(type[i] == "IN")
			cin >> to[i];
		else if(type[i] == "NOT")
			cin >> l[i];
		else
			cin >> l[i] >> r[i];
	}

	dfsdown(1);
	dfsup(1);

	for(int i = 1; i <= n; i++)
		if(type[i] == "IN")
			cout << from[i][!to[i]];

	cout << endl;
}