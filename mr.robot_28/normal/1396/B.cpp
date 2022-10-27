#include<bits/stdc++.h>
 
using namespace std;


signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector <int> a(n);
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		bool flag = 1;
		priority_queue <pair <int, int> > q;
		int last = n;
		for(int i = 0; i < n; i++)
		{
			if(a[i] != 0)
			{
				q.push({a[i], i});
			}
		}
		int cnt = 0;
		vector <int> used(n, -1e9);
		while(q.size() > 0)
		{
			int val = q.top().first;
			int ind = q.top().second;
			q.pop();
			if(used[ind] == cnt - 1)
			{
				if(q.size() == 0)
				{
					break;
				}
				int val1 = q.top().first;
				int ind1 = q.top().second;
				q.pop();
				val1--;
				used[ind1] = cnt;
				if(val1 != 0)
				{
				q.push({val1, ind1});
				}
				q.push({val, ind});
			}
			else
			{
				val--;
				used[ind] = cnt;
				if(val != 0)
				{
				q.push({val, ind});
				}
			}
			cnt++;
		}
		if(cnt % 2 == 0)
		{
			flag = 0;
		}
		if(flag)
		{
			cout << "T\n";
		}
		else
		{
			cout << "HL\n";
		}
	}
	return 0;
}