#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
const int mod = 1e9 + 7;
const int N = 2e5 + 100;
ll Tree_cnt[2][N * 4], Tree_sum[2][N * 4];
void go_to_del(int t, int v, int l, int r, int x)
{
	Tree_cnt[t][v]--;
	Tree_sum[t][v] -= x;
	if(l == r){
		return;
	}
	int m = (r + l) / 2;
	if(x <= m)
	{
		go_to_del(t, v * 2, l, m, x);
	}
	else
	{
		go_to_del(t, v * 2 + 1, m + 1, r, x);
	}
}
ll get_cnt(int t, int v, int l, int r, int al, int ar){
	if(al > ar)
	{
		return 0;
	}
	if(l >= al && r <= ar)
	{
		return Tree_cnt[t][v];
	}
	if(r < al || l > ar)
	{
		return 0;
	}
	return get_cnt(t, v * 2, l, (r + l) / 2, al, ar) + get_cnt(t, v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
}
ll get_sum(int t, int v, int l, int r, int al, int ar)
{
	if(al > ar)
	{
		return 0;
	}
	if(l >= al && r <= ar)
	{
		return Tree_sum[t][v];
	}
	if(r < al || l > ar)
	{
		return 0;
	}
	return get_sum(t, v * 2, l, (r + l) / 2, al, ar) + get_sum(t, v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
}
void build(int v, int l, int r)
{
	if(l == r)
	{
		int t = l & 1;
		Tree_sum[t][v] = l;
		Tree_cnt[t][v] = 1;
		Tree_sum[1 - t][v] = 0;
		Tree_sum[1 - t][v] = 0;
		return;
	}
	build(v * 2, l, (r + l) / 2);
	build(v * 2 + 1, (r + l) / 2 + 1, r);
	for(int t = 0; t < 2; t++)
	{
		Tree_sum[t][v] = Tree_sum[t][v * 2] + Tree_sum[t][v * 2 + 1];
		Tree_cnt[t][v] = Tree_cnt[t][v * 2] + Tree_cnt[t][v * 2 + 1];
	}
}
set <pair <int, int> > st[2];
set <int> st1[2];
vector <int> start[N];
int en[N];
void funct_add(int i, int val)
{
	set <pair <int, int> > :: iterator it;
	it = st[i].lower_bound({val, 0});
	if(it == st[i].end() || it -> X != val)
	{
		st[i].insert({val, 1});
	}
	else
	{
		int c = it -> Y + 1;
		st[i].erase(it);
		st[i].insert({val, c});
	}
}
void funct_del(int i, int val)
{
	set <pair <int, int> > :: iterator it;
	it = st[i].lower_bound({val, 0});
	int c = it -> Y - 1;
	st[i].erase(it);
	if(c != 0)
    {
	st[i].insert({val, c});
    }
}
signed main()
{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		st1[i & 1].insert(i);
	}
	for(int i = 1; i <= n; i++)
	{
		int l, r;
		cin >> l >> r;
		start[l].push_back(r);
		en[r]++;
	}
	ll ans = 0;
	build(1, 1, m);
	int it = m;
	int lst = m + 1;
	for(int i = m; i >= 1; i--)
	{
		while(en[i] > 0)
		{
			funct_add(i & 1, i);
			en[i]--;
		}
	//	cout << i << "\n";
		int t = !(i & 1);
		for(auto v : start[i])
		{
		    lst = i;
			funct_del(v & 1, v);
			int l = i;
			int r = v;
		//	cout << l << " " <<r<< "\n";
			if((r - l + 1) % 2 == 0)
			{
				while(it >= r)
				{
					auto it1 = st1[it & 1].lower_bound(it);
					if(it1 != st1[it & 1].end())
					{
						st1[it & 1].erase(it);
						go_to_del(it & 1, 1, 1, m, it);
					}
					it--;
				}
			}
	//		cout << "a";
			auto it1 = st1[t].lower_bound(i);
			while(it1 != st1[t].end() && *it1 <= r){
				auto it2 = it1;
				it2++;
				go_to_del(t, 1, 1, m, *it1);
				st1[t].erase(*it1);
				it1 = it2;
			}
		}
		//cout << i << "\n";
		if(!sz(st[i & 1]))
		{
			if(!sz(st[t])){
				ll cnt = get_cnt(0, 1, 1, m, lst, m) + get_cnt(1, 1, 1, m, lst, m);
				ll sum = get_sum(0, 1, 1, m, lst, m) + get_sum(1, 1, 1, m, lst, m);
				ans += sum - 1LL * cnt * (i - 1);
			}
			else
			{
				ll cnt = get_cnt(i & 1, 1, 1, m, i, st[t].begin() -> X);
				ll sum = get_sum(i & 1, 1, 1, m, i, st[t].begin() -> X);
				ans += sum - 1LL * cnt * (i - 1);
			}
		}
		else
		{
			if(!sz(st[t]))
			{
				ll cnt = get_cnt(i & 1, 1, 1, m, i, st[i & 1].rbegin() -> X) + get_cnt(0, 1, 1, m, st[i & 1].rbegin() -> X + 1, m) + get_cnt(1, 1, 1, m, st[i & 1].rbegin() -> X + 1, m);
				ll sum = get_sum(i & 1, 1, 1, m, i, st[i & 1].rbegin() -> X) + get_sum(0, 1, 1, m, st[i & 1].rbegin() -> X + 1, m) + get_sum(1, 1, 1, m, st[i & 1].rbegin() -> X + 1, m);
				ans += sum - 1LL * cnt * (i - 1);
			}
			else
			{
				int b = st[t].begin() -> X;
				ll cnt = get_cnt(i & 1, 1, 1, m, i, b);
				ll sum = get_sum(i & 1, 1, 1, m, i, b);
				ans += sum - 1LL * cnt * (i - 1);
			}
		}
	//	cout << ans << "\n";
	}
	cout << ans;
	return 0;
}