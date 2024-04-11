#include<bits/stdc++.h>
using namespace std;
 
signed main()
{
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	stack <int> st;
	vector <pair <int, int> > ans;
	for(int i = 0; i < n - 1; i++)
	{
		if(s[i] == 'R' && s[i + 1] == 'L')
		{
			st.push(i);
		}
	}
	int cnt = 0;
	int timer = 0;
	while(st.size() > 0)
	{
		if(timer > k)
		{
			cout << -1;
			return 0;
		}
		priority_queue <int> st1;
		while(st.size() > 0)
		{
			ans.push_back({st.top(), timer});
			swap(s[st.top()], s[st.top() + 1]);
			if(st.top() != 0 && s[st.top() - 1] == 'R')
			{
				st1.push(st.top() - 1);
			}
			if(st.top() != n - 2 && s[st.top() + 2] == 'L')
			{
				st1.push(st.top() + 1);
			}
			st.pop();
		}
		while(st1.size() > 0)
		{
			st.push(st1.top());
			st1.pop();
		}
		timer++;
	}
	if(ans.size() < k || timer > k)
	{
		cout << -1;
		return 0;
	}
	int ns = 0;
	for(int i = 0; i < ans.size(); i++)
	{
		if(timer + cnt < k)
		{
			if(i == 0 || ans[i].second != ans[i - 1].second)
			{
				cout << 1 << " " << ans[i].first + 1 << "\n";
			}
			else
			{
				cout << 1 << " " << ans[i].first + 1 << "\n";
			}
			if(i != ans.size() - 1 && ans[i + 1].second == ans[i].second){
				cnt++;
			}
			ns++;
		}
		else
		{
			ns++;
			int j = i;
			int u = 0;
			while(j < ans.size() && ans[i].second == ans[j].second)
			{
				u++;
				j++;
			}
			cout << u << " ";
			j = i;
			while(j < ans.size() && ans[i].second == ans[j].second)
			{
				cout << ans[j].first + 1 << " ";
				j++;
			}
			cout << "\n";
			i = j - 1;
		}
	}
    return 0;
}