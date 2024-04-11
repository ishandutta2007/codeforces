#include<bits/stdc++.h>
using namespace std;
#define int long long
const int q = 13;
int query(vector <int> ask)
{
	cout << "? " << ask.size() << " ";
	for(int i = 0; i < ask.size(); i++)
	{
		cout << ask[i] + 1 << " ";
	}
	cout << endl;
	fflush(stdout);
	int a;
	cin >> a;
	return a;
}
signed main() {
	int n;
	cin >> n;
	vector <vector <int> > w(q);
	vector <int> mask(n);
	vector <int> value(q, 0);
	int j = 0;
	for(int i = 1; i < (1 << q); i++)
	{
		if(__builtin_popcount(i) != q / 2)
		{
			continue;
		}
		mask[j] = i;
		for(int u = 0; u < q; u++){
			if((i & (1 << u)) == 0)
			{
				w[u].push_back(j);
			}
		}
		j++;
		if(j == n)
		{
			break;
		}
	}
	for(int i = 0; i < q; i++)
	{
		if(w[i].size() != 0){
			value[i] = query(w[i]);
		}
	}
	vector <int> ans(n, 0);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < q; j++)
		{
			if((mask[i] & (1 << j)) != 0)
			{
				ans[i] |= value[j];
			}
		}
	}
	cout << "! ";
	for(int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	fflush(stdout);
	return 0;
}