#include<bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> ans(n);
	set <int> st;
	vector <pair <int, int> > mass(n * 2);
	for(int i = 0; i < n * 2; i++)
	{
		char t;
		cin >> t;
		if(t == '+')
		{
			mass[i].second = 1;
		}
		else
		{
			mass[i].second = -1;
			cin >> mass[i].first;
			mass[i].first--;
		}
	}
	for(int i = n * 2 - 1; i >= 0; i--)
	{
		if(mass[i].second == -1)
		{
			st.insert(mass[i].first);
		}
		else
		{
			if(st.size() == 0)
			{
				cout << "NO";
				return 0;
			}
			mass[i].first = *st.begin();
			st.erase(*st.begin());
		}
	}
	for(int i = 0; i < n * 2; i++)
	{
		if(mass[i].second == -1)
		{
			int a = *st.begin();
			st.erase(*st.begin());
			if(a != mass[i].first){
				cout << "NO";
				return 0;
			}
		}
		else
		{
			st.insert(mass[i].first);
		}
	}
	cout << "YES\n";
	for(int i = 0; i < n * 2; i++)
	{
		if(mass[i].second == 1)
		{
			cout << mass[i].first + 1 << " ";
		}
	}
	return 0;
}