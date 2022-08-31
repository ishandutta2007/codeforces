#include<set>
#include<map>
#include<ctime>
#include<string>
#include<vector>
#include<stdio.h>
#include<fstream>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5, K = 1024;

int g[N];
pair<int, int> ans[N];

int main()
{
	//int tm = clock();
	//ifstream in;
	//ofstream out;
	//in.open("input.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, t, v, u;
	cin >> n >> m;

	for (int i = 0, x; i < n; i++)
	{
		cin >> x;
		g[i] = -1;
		if (i + x < n)
		{
			g[i] = i + x;
		}
	}

    for (int i = n / K; i >= 0; --i) {
		for (int j = (i + 1) * K - 1; j >= i * K; j--)
		{
			if (j >= n)
			{
				continue;
			}

			if (g[j] == -1)
			{
				ans[j] = { j, 1 };
			}
			else if (j / K != g[j] / K)
			{
				ans[j] = { g[j], 1 };
			}
			else
			{
				if (g[g[j]] == -1 && ans[g[j]].first == g[j])
				{
					ans[j] = { ans[g[j]].first, ans[g[j]].second };
				}
				else
				{
					ans[j] = { ans[g[j]].first, ans[g[j]].second + 1 };
				}
			}
		}
	}

	//out.open("output.txt");
	//out.tie(0);

	while (cin >> t)
	{
		cin >> v;
		--v;

		if (t == 0)
		{
			cin >> u;

			if ((v + u) < n)
			{
				g[v] = v + u;
			}
			else
			{
				g[v] = -1;
			}

            int to = v / K * K;
			for (int j = v; j >= to; j--)
			{
				if (j >= n)
				{
					continue;
				}
                int gj = g[j];
				if (gj == -1) {
					ans[j] = { j, 1 };
				} else if (j / K != gj / K) {
					ans[j] = { gj, 1 };
				} else {
				    auto ansgj = ans[gj];
				    int e = g[gj] != -1 || ansgj.first != gj;
					ans[j] = { ansgj.first, ansgj.second + e };
				}
			}
		}
		else
		{
			int res = 0;
			while (g[v] != -1)
			{
				res += ans[v].second;
				v = ans[v].first;
			}

			cout << v + 1 << " " << res + 1 << '\n';
		}
	}

	//in.close();
	//out.close();

	//cout << "done!(" << float(clock() - tm) / CLOCKS_PER_SEC << "s)";
	return 0;
}