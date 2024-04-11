#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const double eps = 1e-9;
vector <int> tree;
vector <int> upd;
void push(int v, int l, int r)
{
	tree[v * 2] += upd[v];
	tree[v * 2 + 1] += upd[v];
	upd[v * 2] += upd[v];
	upd[v * 2 + 1] += upd[v];
	upd[v] = 0;
}
void update(int v, int l, int r, int al, int ar, int val)
{
	if(l >= al && r <= ar)
	{
		tree[v] += val;
		upd[v] += val;
	}
	else if(l  <= ar && r >= al)
	{
		push(v, l, r);
		update(v * 2, l, (r + l) / 2, al, ar, val);
		update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
		tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
	}
}
int ans(int v, int l, int r, int ind)
{
	if(l == r)
	{
		return tree[v];
	}
	else if(ind <= (r + l) / 2)
	{
		push(v, l, r);
		return ans(v * 2, l, (r + l) / 2, ind);
	}
	else
	{
		push(v, l, r);
		return ans(v * 2 + 1, (r + l) / 2 + 1, r, ind);
	}
}
int ans1(int v, int l, int r, int al, int ar, int val)
{
	if(l >= al && r <= ar)
	{
		if(tree[v] + val <= 0)
		{
			if(l == r)
			{
				return l;
			}
			push(v, l, r);
			if(tree[v * 2] + val <= 0)
			{
				return ans1(v * 2, l, (r + l) / 2 , al, ar, val);
			}
			return ans1(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
		}
		else
		{
			return -1;
		}
	}
	else if(l <= ar && r >= al)
	{
		push(v, l, r);
		int t = ans1(v * 2, l, (r + l) / 2, al, ar, val);
		if(t == -1)
		{
			return ans1(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
		}
		return t;
	}
	else
	{
		return -1;
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin >> q;
	vector <int> type(q);
	vector <pair <pair <int, int>, int> > query(q);
	vector <int> uniq;
	for(int i = 0; i < q; i++)
	{
		cin >> type[i];
		if(type[i] == 1)
		{
			int t, s;
			cin >> t >> s;
			query[i] = {{t, s}, -1};
			uniq.push_back(t);
		}
		else if(type[i] == 2)
		{
			int t;
			cin >> t;
			query[i] = {{t, -1}, -1};
			uniq.push_back(t);
		}
		else
		{
			int l, r, v;
			cin >> l >> r >> v;
			query[i] = {{l, r}, v};
		}
	}
	sort(uniq.begin(), uniq.end());
	int m = unique(uniq.begin(), uniq.end()) - uniq.begin();
	tree.resize(4 * m);
	upd.resize(4 * m);
	set <int> timer;
	vector <int> up(m);
	for(int i = 0; i < type.size(); i++)
	{
		if(type[i] == 1)
		{
			int t = query[i].first.first;
			set <int> :: iterator r = timer.lower_bound(t);
			set <int> :: iterator p;
			p = r;
			int it = lower_bound(uniq.begin(), uniq.begin() + m, t) - uniq.begin();
			up[lower_bound(uniq.begin(), uniq.begin() + m, t) - uniq.begin()] = query[i].first.second;
			if(p != timer.begin())
			{
				p--;
				if(r != timer.end())
				{
					int delta = *r - *p;
					int iter = lower_bound(uniq.begin(), uniq.begin() + m, *p) - uniq.begin();
					delta *= up[iter];
					update(1, 0, m - 1, lower_bound(uniq.begin(), uniq.begin() + m, *r) - uniq.begin(), m - 1, -delta);
				}
			}
			if(r != timer.end()){
				int delta = *r - t;
					delta *= query[i].first.second;
					update(1, 0, m - 1, lower_bound(uniq.begin(), uniq.begin() + m, *r) - uniq.begin(), m - 1, delta);
				
			}
			p = r;
			if(p != timer.begin())
			{
				p--;
				int delta = t - *p;
				int iter = lower_bound(uniq.begin(), uniq.begin() + m, *p) - uniq.begin();
				delta *= up[iter];
				update(1, 0, m - 1, lower_bound(uniq.begin(), uniq.begin() + m, t) - uniq.begin(), m - 1, delta);
			}
			timer.insert(t);
		}
		else if(type[i] == 2){
			int t = query[i].first.first;
			int iter = lower_bound(uniq.begin(), uniq.begin() + m, t) - uniq.begin();
			set <int> :: iterator r = timer.upper_bound(t);
			set <int> :: iterator p = timer.lower_bound(t);
			if(r != timer.end())
			{
				int iter1 = lower_bound(uniq.begin(), uniq.begin() + m, *r) - uniq.begin();
				update(1, 0, m - 1, iter1, m - 1, -(*r - t) * up[iter]);
			}
			if(p != timer.begin())
			{
				p--;
				int iter1 = lower_bound(uniq.begin(), uniq.begin() + m, *p) - uniq.begin();
				update(1, 0, m - 1, iter, m - 1, -(t - *p) * up[iter1]);
				if(r != timer.end())
				{
					update(1,  0, m - 1, lower_bound(uniq.begin(), uniq.begin() + m, *r) - uniq.begin(), m - 1, (*r - *p) * up[iter1]);
				}
			}
			timer.erase(t);
		}
		else
		{
			int l = query[i].first.first;
			int r = query[i].first.second;
			int v = query[i].second;
			set <int> :: iterator it;
			it = timer.lower_bound(l);
			if(v == 0){
				cout << l << "\n";
				continue;
			}
			if(timer.size() == 0)
			{
				cout << -1 << "\n";
				continue;
			}
			else if(it == timer.begin())
			{
				int u = ans1(1, 0, m - 1, 0, m - 1, v);
				int e = *timer.rbegin();
				if(u == -1 && up[lower_bound(uniq.begin(), uniq.begin() + m, e) - uniq.begin()] >= 0)
				{
					cout << -1 << "\n";
				}
				else if(u == -1)
				{
					int delta = ans(1, 0, m - 1, lower_bound(uniq.begin(), uniq.begin() + m, e) - uniq.begin()) - ans(1, 0, m - 1, lower_bound(uniq.begin(), uniq.begin() + m, *it) - uniq.begin());
					v += delta;
					double x = v * 1.0 / (-up[lower_bound(uniq.begin(), uniq.begin() + m, e) - uniq.begin()]);
					x += e;
					if(x - eps > r)
					{
						cout << -1 << "\n";
						continue;
					}
					cout << fixed << setprecision(10) << x << "\n";
				}
				else
				{
					set <int> :: iterator it1;
					it1 = timer.lower_bound(uniq[u]);
					it1--;
					int delta = ans(1, 0, m - 1, lower_bound(uniq.begin(), uniq.begin() + m, *it1) - uniq.begin()) - ans(1, 0, m - 1, lower_bound(uniq.begin(), uniq.begin() + m, *it) - uniq.begin());
					v += delta;
					double x =v * 1.0 / (-up[lower_bound(uniq.begin(), uniq.begin() + m, *it1) - uniq.begin()]);
					x += *it1;
					if(x - eps > r)
					{
						cout << -1 << "\n";
						continue;
					}
					cout << fixed << setprecision(10) << x << "\n";
				}
			}
			else if(v == 0)
			{
				cout << l << "\n";
			}
			else if(it == timer.end())
			{
				cout << -1 << "\n";
			}
			else
			{
				set <int> :: iterator it1, it5;
				it1 = it;
				int iter1 = lower_bound(uniq.begin(), uniq.begin() + m, *it) - uniq.begin();
				v -= ans(1, 0, m - 1, iter1);
				int e = *timer.rbegin();
					int  u = ans1(1, 0, m - 1, iter1, m - 1, v);
					int riter = lower_bound(uniq.begin(), uniq.begin() + m, e) - uniq.begin();
					if(u == -1 && up[riter] >= 0)
					{
						cout << -1 << "\n";
					}
					else if(u == -1)
					{
						v += ans(1, 0, m - 1, riter);
						double x = v * 1.0 / (-up[riter]);
						x += e;
						if(x - eps > r)
						{
							cout << -1 << "\n";
							continue;
						}
						cout << fixed << setprecision(10) << x << "\n";
					}
					else
					{
						set <int> :: iterator it1;
						it1 = timer.lower_bound(uniq[u]);
						it1--;
						int delta = ans(1, 0, m - 1, lower_bound(uniq.begin(), uniq.begin() + m, *it1) - uniq.begin());
						v += delta;
						double x =v * 1.0 / (-up[lower_bound(uniq.begin(), uniq.begin() + m, *it1) - uniq.begin()]);
						x += *it1;
						if(x - eps > r)
						{
							cout << -1 << "\n";
							continue;
						}
						cout << fixed << setprecision(10) << x << "\n";
					}
			}
		}
	}
    return 0;
}