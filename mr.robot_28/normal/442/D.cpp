#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	n++;
	vector <int> p(n);
	vector <int> max1(n), max2(n);
	vector <int> ans(n);
	vector <int> imax1(n, -1), imax2(n, -1);
	vector <vector <int> > g(n);
	for(int i = 1; i < n; i++){
		cin >> p[i];
		p[i]--;
		g[p[i]].push_back(i);
		int k = i;
		max1[k] = 0;
		max2[k] = 0;
		ans[k] = 1;
		while(k != 0)
		{
			int pred = p[k];
			int p1 = ans[pred];
			if(imax1[pred] == k && ans[k] > max1[pred])
			{
				max1[pred] = ans[k];
			}
			else if(ans[k] > max1[pred])
			{
				max2[pred] = max1[pred];
				imax2[pred] = imax1[pred];
				max1[pred] = ans[k];
				imax1[pred] = k;
			}
			else if(ans[k] > max2[pred])
			{
				imax2[pred] = k;
				max2[pred] = ans[k];
			}
			ans[pred] = max(max1[pred], max2[pred] + 1);
			if(p1 == ans[pred])
			{
				break;
			}
			k = pred;
		}
		cout << max1[0] << " ";
	}
	return 0;
}