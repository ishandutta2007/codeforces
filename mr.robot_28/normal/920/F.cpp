# include <bits/stdc++.h>
using namespace std;
#define int long long
vector <int> A, cnt;
vector <int> nex(1e6 + 1);
vector <int> fenv, fenv1;
set <int> s;
void update1(int i, int a)
{
	while(i < A.size())
	{
		fenv[i] += a;
		i = (i | (i + 1));
	}
}
void update(int i)
{
	int cnt = nex[A[i]];
	int delta = cnt - A[i];
	A[i] = cnt;
	while(i < A.size())
	{
		fenv[i] += delta;
		i = (i | (i + 1));
	}
}
void upd(int l, int r)
{
	set <int> :: iterator it;
	it = s.lower_bound(l);
	vector <int> e;
	while(it != s.end() && *it <= r)
	{
		update(*it);
		cnt[*it]++;
		if(cnt[*it] == 6)
		{
			e.push_back(*it);
		}
		it++;
	}
	for(int i = 0; i < e.size(); i++)
	{
		s.erase(e[i]);
	}
}
int sum(int a){
	if(a < 0)
	{
		return 0;
	}
	int ans = 0;
	while(a >= 0)
	{
		ans += fenv[a];
		a = (a & (a + 1)) - 1;
	}
	return ans;
}
signed main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	A.resize(n);
	cnt.resize(n);
	fenv.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		cnt[i] = 0;
		s.insert(i);
		update1(i, A[i]);
	}
	for(int i = 1; i <= 1e6; i++)
	{
		int k = i;
		while(k <= 1e6)
		{
			nex[k]++;
			k += i;
		}
	}
	for(int i = 0; i < m; i++)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			upd(l, r);
		}
		else
		{
			int l, r;
			cin >> l >> r;
			cout << sum(r - 1) - sum(l - 2) << "\n";
		}
	}
	return 0;
}