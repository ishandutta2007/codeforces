#include<bits/stdc++.h>
 
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	int sum1 = 0, sum2 = 0;
	vector <int> up(n);
	int sum = 0;
	int anssum = 0;
	for(int i = 0; i < n; i++)
	{
		if(i % 2 == 0)
		{
			sum1 += (a[i] - '0');
			sum2 += (b[i] - '0');
		}
		else
		{
			sum1 -= (a[i] - '0');
			sum2 -= (b[i] - '0');
		}
		int a1 = a[i] - '0' + sum;
		int b1 = b[i] - '0';
		up[i] = b1 - a1;
		sum = b1 - a1;
		anssum += abs(b1 - a1);
	}
	if(sum1 != sum2)
	{
		cout << -1;
		return 0;
	}
	queue <pair <int, int> > Q;
	vector <vector <bool> > used(n, vector <bool> (2));
	for(int i = 0; i < n - 1; i++)
	{
		if(up[i] != 0)
		{
			int a1 = a[i] - '0';
			int a2 = a[i + 1] - '0';
			if(up[i] > 0 && a1 < 9 && a2 < 9)
			{
				Q.push({i, 1});
				used[i][0] = true;
			}
			if(up[i] < 0 && (i == 0 && a1 > 1 && a2 > 0 || i != 0 && a1 > 0 && a2 > 0))
			{
				Q.push({i, -1});
				used[i][1] = true;
			}
		}
	}
	int cnt = 0;
	vector <pair <int, int> > ans;
	while(Q.size() != 0)
	{
		int v = Q.front().first;
		int type = Q.front().second;
		Q.pop();
		if(type == 1)
		{
			used[v][0] = false;
		}
		else
		{
			used[v][1] = false;
		}
		while(type == 1 && a[v] - '0' < 9 && a[v + 1] - '0' < 9 && up[v] > 0)
		{
			ans.push_back({v + 1, 1});
			a[v]++;
			a[v + 1]++;
			cnt++;
			up[v]--;
		}
		while(type == -1 && (v == 0 && a[v] - '0' > 1 && a[v + 1] - '0' > 0 || v > 0 && a[v] - '0' > 0 && a[v + 1] - '0' > 0) && up[v] < 0)
		{
			ans.push_back({v + 1, -1});
			cnt++;
			up[v]++;
			a[v]--;
			a[v + 1]--;
		}
		if(v < n - 1 && !used[v + 1][0] && a[v + 1] - '0' < 9 && a[v + 2] - '0' < 9 && up[v + 1] > 0)
		{
			used[v + 1][0] = true;
			Q.push({v + 1, 1});
		}
		if(v < n - 1 && !used[v + 1][1] && a[v + 1] - '0' > 0 && a[v + 2] - '0' > 0 && up[v + 1] < 0)
		{
			used[v + 1][1] = true;
			Q.push({v + 1, -1});
		}
		if(v > 0 && !used[v - 1][0] && a[v - 1] - '0' < 9 && a[v] - '0' < 9 && up[v - 1] > 0)
		{
			used[v - 1][0] = true;
			Q.push({v - 1, 1});
		}
		if(v > 0 && !used[v - 1][1] && (v == 1 && a[v - 1] - '0' > 1 && a[v] - '0' > 0 || v > 1 && a[v - 1] - '0' > 0 && a[v] - '0' > 0) && up[v - 1] < 0)
		{
			used[v - 1][1] = true;
			Q.push({v - 1, -1});
		}
		if(cnt >= 1e5)
		{
			break;
		}
	}
	cout << anssum << "\n";
	if(100000 < cnt)
	{
		cnt = 100000;
	}
	for(int i = 0; i < cnt; i++)
	{
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
	return 0;
}