#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <queue>
#include <stack>
#include <bitset>
#define y1 y11
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define NAME ""

using namespace std;
	
typedef long long ll;
typedef long double ld;

const ld PI = acos(-1.0);

const int MAXN = 50001;
const int MAXM = 1000001;
int cf[MAXM];
vector <int> e[MAXN];
int ans[MAXN];
vector <int> tt[MAXN];
bool w[MAXN][2];
vector <int> t2[MAXM];


int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	int t;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		e[max(a, b)].push_back(min(a, b));
	}
	for (int i = 1; i <= n; i++)
	{
		int cn;
		cin >> cn;
		for (int j = 0; j < cn; j++)
		{
			int x;
			cin >> x;
			t = max(t, x);
			tt[i].push_back(x);
			t2[x].push_back(i);
		}
	}
	while (true)
	{
		for (int i = 1; i <= t; i++) cf[i]= rand() % 2;
		bool ok = true;
		for (int i = 1; i <= n; i++)
		{
			bool wc[2] = {false, false};
			for (int j = 0; j < tt[i].size(); j++)
				wc[cf[tt[i][j]]] = true;
			ok &= wc[0];
			ok &= wc[1];
		}
		if (ok) break;
	}
	for (int i = 1; i <= n; i++)
	{
		int c[2] = {0, 0};
		for (int j = 0; j < e[i].size(); j++)
		{
			c[cf[ans[e[i][j]]]]++;
		}
		int nd = 0;
		if (c[1] < c[0]) nd = 1;
		for (int j = 0; j < tt[i].size(); j++)
		{
			if (cf[tt[i][j]] == nd) ans[i] = tt[i][j];
		}
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	cout << endl;
	for (int i = 1; i <= t; i++) cout << cf[i]+ 1 << " ";
	cout << endl;
	return 0;
}