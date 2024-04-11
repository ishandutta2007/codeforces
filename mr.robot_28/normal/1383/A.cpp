#include<bits/stdc++.h>
 
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		vector <set <int> > st(20);
		bool flag = 1;
		for(int i = 0; i < n; i++)
		{
			if(a[i] != b[i])
			{
				if(a[i] - 'a' > b[i] - 'a')
				{
					flag = false;
				}
				st[a[i] - 'a'].insert(b[i] - 'a');
			}
		}
		if(!flag)
		{
			cout << -1 << "\n";
			continue;
		}
		set <pair <int, int> > s1;
		for(int i = 0; i < 20; i++)
		{
			if(st[i].size() != 0)
			{
				s1.insert({*st[i].begin(), i});
			}
		}
		int cnt = 0;
		while(s1.size() != 0){
			vector <int> vec;
			int a = s1.begin() -> first;
			while(s1.size() > 0 && s1.begin() -> first == a)
			{
				vec.push_back(s1.begin() -> second);
				s1.erase(s1.begin());
			}
			cnt += vec.size();
			if(st[a].size() != 0)
			{
			s1.erase(s1.find({*st[a].begin(), a}));
			}
			for(int i = 0; i < vec.size(); i++)
			{
				set <int> :: iterator it;
				for(it = st[vec[i]].begin(); it != st[vec[i]].end(); it++)
				{
					st[a].insert(*it);
				}
			}
			st[a].erase(a);
			if(st[a].size() != 0)
			{
				s1.insert({*st[a].begin(), a});
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}