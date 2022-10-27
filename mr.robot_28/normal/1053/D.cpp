#include<bits/stdc++.h>
using namespace std;
#define int long long
const int const1 = 1e9 + 7;
int power(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	else if(b % 2 == 0)
	{
		int t = power(a, b / 2);
		return t * t % const1;
	}
	else
	{
		int t = power(a, b / 2);
		t = t * t % const1;
		return t * a % const1;
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> erat(2e6 + 1, -1);
	for(int i = 2; i <= 2e6; i++)
	{
		if(erat[i] == -1){
			int j = i;
			while(j <= 2e6)
			{
				erat[j] = i;
				j += i;
			}
		}
	}
	vector <int> p(n);
	for(int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	sort(p.begin(), p.end());
	reverse(p.begin(), p.end());
	bool flag = true;
	set <pair <int, pair <int, int> > > st;
	int c = 1, pp = 0;
	vector <int> type(n);
	for(int i = 0; i < n; i++)
	{
		set <pair <int, pair <int, int> > > :: iterator it;
		it = st.lower_bound({p[i], {0, 0}});
		if(it != st.end() && it -> first == p[i])
		{
			type[i] = 2;
			int a = p[i] - 1;
			while(a > 1)
			{
				int cnt1 = 0;
				int q = erat[a];
				while(a % q == 0)
				{
					cnt1++;
					a = a / q;
				}
				it = st.lower_bound({q, {0, 0}});
				if(it == st.end() || it -> first != q)
				{
					st.insert({q, {cnt1, 1}});
				}
				else if(it -> second.first < cnt1)
				{
					st.erase(*it);
					st.insert({q, {cnt1, 1}});
				}
				else if(it -> second.first == cnt1)
				{
					int cnt2 = 1 + it -> second.second;
					st.erase(*it);
					st.insert({q, {cnt1, cnt2}});
				}
			}
		}
		else
		{
			type[i] = 1;
			st.insert({p[i], {1, 1}});
		}
	}
	
	set <pair <int, pair <int, int> > > :: iterator it;
	for(int i = 0; i < n; i++)
	{
		if(type[i] == 1)
		{
			it = st.lower_bound({p[i], {0, 0}});
			if(it -> second.first > 1 || it -> second.second > 1)
			{
				pp = 1;
			}
		}
		else
		{
			int a = p[i] - 1;
			if(p[i] - 1 == 1){
				pp = 1;
			}
			bool flag = true;
			while(a > 1)
			{
				int q = erat[a];
				int cnt1 = 0;
				while(a % q == 0)
				{
					cnt1++;
					a = a / q;
				}
				it = st.lower_bound({q, {0, 0}});
				if(it ->second.first == cnt1 && it -> second.second == 1)
				{
					flag = false;
				}
			}
			if(flag)
			{
				pp = 1;
			}
		}
	}
	for(it = st.begin(); it != st.end(); it++)
	{
		c = c * power(it -> first, it -> second.first) % const1;
	}
	cout << (c + pp) % const1;
	return 0;
}