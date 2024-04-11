#include<bits/stdc++.h>
 
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x;
	cin >> x;
	vector <int> p(x + 1, -1);
	vector <int> last(x + 1, -1);
	vector <int> d(x + 1, 0);
	for(int i = 2; i <= x; i++)
	{
		int j = i;
		if(p[i] == -1)
		{
			while(j <= x)
			{
				p[j] = i;
				j += i;
			}
		}
	}
	int ans = 1e9;
	priority_queue <pair <int, int> > q1, q2;
	int cnt0 = 0, cnt1 = 0;
	for(int i = x; i >= 3; i--)
	{
		vector <int> mass1;
		int t = i;
		while(t != 1)
		{
			mass1.push_back(p[t]);
			int k = p[t];
			while(t % k == 0)
			{
				t = t / k;
			}
		}
		int mx = 0;
		for(int j = 0; j < mass1.size(); j++)
		{
			mx = max(mx, mass1[j]);
		}
		while(q1.size() > 0 && q1.top().first > i)
		{
			q1.pop();
		}
		while(q2.size() > 0 && q2.top().first > i)
		{
			q2.pop();
		}
		int fl = 2;
		if(i == x)
		{
			fl = 0;
			if(mass1.size() != 1)
			{
				ans = i;
			}
		}
		else if(q1.size() != 0)
		{
			fl = 1;
				ans = i;
		}
		else if(q2.size() != 0)
		{
			ans = i;
		}
		if(fl == 0)
		{
			if(mass1.size() != 1 || mass1[0] != i)
			{
				q1.push({i - mx + 1, i});
			}
		}
		else if(fl == 1)
		{
			if(mass1.size() != 1 || mass1[0] != i)
			{
				q2.push({i - mx + 1, i});
			}
		}
	}
	cout << ans;
    return 0;
}