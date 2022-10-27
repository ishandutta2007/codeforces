#include<bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> ans1(n), ans2(n);
	int del[10000001];
	for(int i = 1; i <= 1e7; i++)
	{
		del[i] = -1;
	}
	for(int j = 2; j <= 1e7; j++)
	{
		if(del[j] != -1)
		{
			continue;
		}
		int d = j;
		while(d <= 1e7)
		{
			del[d] = j;
			d += j;
		}
	}
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		set <int> st;
		while(a != 1)
		{
			st.insert(del[a]);
			a = a / del[a];
		}
		if(st.size() == 1){
			ans1[i] = ans2[i] = -1;
		}
		else
		{
			ans1[i] = *st.begin();
			st.erase(st.begin());
			int p = 1;
			set <int> :: iterator it;
			for(it = st.begin(); it != st.end(); it++)
			{
				p = p * (*it);
			}
			ans2[i] = p;
		}
	}
	for(int i = 0; i < n; i++)
	{
		cout << ans1[i] << " ";
	}
	cout << "\n";
	for(int i = 0; i < n; i++)
	{
		cout << ans2[i] << " ";
	}
    return 0;
}