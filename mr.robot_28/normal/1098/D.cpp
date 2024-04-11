#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin >> q;
	vector <multiset <int> > Q(31);
	vector <int> sum(31);
	int allcnt = 0;
	while(q--)
	{
		char t;
		int x;
		cin >> t >> x;
		if(t == '+')
		{
			allcnt++;
			int c =0 ;
			for(int w = 1; w <= (1 << 30);w *= 2 )
			{
				if(x >= w && x < w * 2)
				{
					Q[c].insert(x);
					sum[c] += x;
				}
				c++;
			}
		}
		else
		{
			allcnt--;
			int c = 0;
			for(int w = 1; w <= (1 << 30); w *= 2)
			{
				if(x >= w && x < w * 2)
				{
					Q[c].erase(Q[c].find(x));
					sum[c] -= x;
				}
				c++;
			}
		}
		int sum1 = 0;
		int ans = allcnt;
		for(int c = 0; c < 31; c++)
		{
			if(Q[c].size() != 0)
			{
				int v = *Q[c].begin();
				if(v > sum1)
				{
					ans--;
				}
			}
			sum1 += 2 * sum[c];
		}
		cout << ans << "\n";
	}
    return 0;
}