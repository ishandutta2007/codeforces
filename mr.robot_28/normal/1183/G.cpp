#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for(int k = 0; k < t; k++)
	{
	int n;
	cin >> n;
	vector <int> cnt(n), cnt1(n);
	for(int i = 0; i < n; i++)
	{
		int a, type;
		cin >> a >> type;
		a--;
		cnt[a]++;
		if(type)
		{
			cnt1[a]++;
		}
	}
	vector <vector <int> > types(n + 1);
	for(int i = 0; i < n; i++)
	{
		types[cnt[i]].push_back(cnt1[i]);
	}
	int ans1 = 0, ans2 = 0;
	multiset <int> cur;
	for(int i = n;  i > 0; i--)
	{
		for(auto x : types[i]) cur.insert(x);
		if(!cur.empty())
		{
			int z = *cur.rbegin();
			ans1 += i;
			ans2 += min(i, z);
			cur.erase(cur.find(z));
		}
	}
	cout << ans1 << " " << ans2 << endl;
	}
	return 0;
}