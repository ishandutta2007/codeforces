#include<bits/stdc++.h>

using namespace std;


signed main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector <vector <char> > a(n, vector <char> (m));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	vector <bool> used(n), used1(m);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(a[i][j] == '#' && !used[i] && !used1[j])
			{
				int cnt1 = 0, cnt2 = 0;
				int c = 0;
				queue <int> q1, q2;
				q1.push(i);
				q2.push(j);
				used[i] = used1[j] = 1;
				while(q1.size() + q2.size() != 0)
				{
					while(q1.size() != 0)
					{
						cnt1++;
						int v = q1.front();
						q1.pop();
						for(int k = 0; k < m; k++)
						{
							if(a[v][k] == '#')
							{
								c++;
							}
							if(a[v][k] == '#' && !used1[k])
							{
								used1[k] = 1;
								q2.push(k);
							}
						}
					}
					while(q2.size() != 0)
					{
						cnt2++;
						int v = q2.front();
						q2.pop();
						for(int k = 0; k < n; k++)
						{
							if(a[k][v] == '#' && !used[k])
							{
								used[k] = 1;
								q1.push(k);
							}
						}
					}
				}
	//			cout << c << " " << cnt1 << " " << cnt2 << "\n";
				if(c < cnt1 * cnt2)
				{
					cout << "No\n";
					return 0;
				}
			}
		}
	}
	cout << "Yes";
	return 0;
}