#include<bits/stdc++.h>
 
using namespace std;
#define int long long
vector <int> treemin, treemax, treesum, upd;
void push(int v, int l, int r)
{
	if(l == r)
	{
		return;
	}
	treemin[v * 2] += upd[v];
	treemin[v * 2 + 1] += upd[v];
	treemax[v * 2] += upd[v];
	treemax[v * 2 + 1] += upd[v];
	treesum[v * 2] += ((r + l) / 2 - l + 1) * upd[v];
	treesum[v * 2 + 1] += (r - (r + l) / 2) * upd[v];
	upd[v * 2] += upd[v];
	upd[v * 2 + 1] += upd[v];
	upd[v] = 0;
}
void update(int v, int l, int r, int al, int ar, int up)
{
	if(l >= al && r <= ar)
	{
		upd[v] += up;
		treesum[v] += (r - l + 1) * up;
		treemin[v] += up;
		treemax[v] += up;
	}
	else if(l <= ar && r >= al)
	{
		push(v, l, r);
		update(v * 2, l, (r + l) / 2, al, ar, up);
		update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, up);
		treesum[v] = treesum[v * 2] + treesum[v * 2 + 1];
		treemin[v] = min(treemin[v * 2], treemin[v * 2 + 1]);
		treemax[v] = max(treemax[v * 2], treemax[v * 2 + 1]);
	}
}
int ansind(int v, int l, int r, int al, int ar, int ind)
{
	if(l >= al && r <= ar)
	{
		push(v, l, r);
		if(treemax[v] < ind)
		{
			return -1;
		}
		if(l == r)
		{
			if(treemin[v] < ind)
			{
				return -1;
			}
			return l;
		}
		if(treemax[v * 2 + 1] >= ind)
		{
			return ansind(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, ind); 
		}
		return ansind(v * 2, l, (r + l) / 2, al, ar, ind);
	}
	else if(l <= ar && r >= al)
	{
		push(v, l, r);
		int val1 = ansind(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, ind);
		if(val1 == -1)
		{
			return ansind(v * 2, l,  ( r+ l) / 2, al, ar, ind);
		}
		return val1;
	}
	else
	{
		return -1;
	}
}
int anssum(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		return treesum[v];
	}
	else if(l <= ar && r >= al)
	{
		push(v, l, r);
		return anssum(v * 2, l, (r + l) / 2, al, ar) + anssum(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
	}
	return 0;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, p, q, r;
	cin >> n >> p >> q >> r;
	treemin.resize(4 * q, 0);
	treemax.resize(4 * q, 0);
	treesum.resize(4 * q, 0);
	upd.resize(4 * q, 0);
	vector <pair <pair <int, int>, int> > mass(n);
	for(int i = 0; i < n; i++)
	{
		cin >> mass[i].first.first >> mass[i].first.second >> mass[i].second;
		mass[i].first.first--;
		mass[i].first.second--;
		mass[i].second--;
	}
	sort(mass.begin(), mass.end());
	vector <int> post1(n + 1, 0), post2(n + 1, 0);
	for(int i = n - 1; i >= 0; i--)
	{
		post1[i] = max(post1[i + 1], mass[i].first.second);
		post2[i] = max(post2[i + 1], mass[i].second);
	}
	int ans = 0;
	set <pair <int, int> > s;
	for(int i = 0; i < n; i++)
	{
		if(post1[i] < q - 1 && post2[i] < r - 1)
		{
			int val1 = post1[i] + 1;
			int val2 = post2[i] + 1;
			int res = mass[i].first.first;
			if(i != 0)
			{
				res -= mass[i - 1].first.first;
			}
			else
			{
				res++;
			}
			int ind = ansind(1, 0, q - 1, val1, q - 1, val2);
			if(ind == -1)
			{	
				ans += res * (q - val1) * (r - val2);
			}
			else
			{
				ans += res * (r * (ind - val1 + 1) - anssum(1, 0, q - 1, val1, ind));
				ans += res * (q - ind - 1) * (r - val2);
			}
		}
		set <pair <int, int> > :: iterator it;
		it = s.lower_bound({mass[i].first.second, 0});
		if(s.size() == 0)
		{
			update(1, 0, q - 1, 0, mass[i].first.second, mass[i].second + 1);
			s.insert({mass[i].first.second, mass[i].second + 1});
			continue;
		}
		if(it != s.end() && it -> second > mass[i].second + 1)
		{
			continue;
		}
		if(it == s.begin())
		{
			update(1, 0, q - 1, 0, mass[i].first.second, mass[i].second + 1 - it -> second);
			if(it -> first == mass[i].first.second){
				s.erase(it);
			}
			s.insert({mass[i].first.second, mass[i].second + 1});
			continue;
		}
		set <pair <int, int> > :: iterator it1;
		it1 = it;
		it1--;
		int vals = 0;
		if(it != s.end())
		{
			vals = it -> second;
		}
		update(1, 0, q - 1, it1 -> first + 1, mass[i].first.second, mass[i].second + 1 - vals);
		if(it != s.end() && it -> first == mass[i].first.second)
		{
			s.erase(it);
		}
		while(s.size() > 0)
		{
			it = s.lower_bound({mass[i].first.second, 0});
			if(it == s.begin())
			{
				break;
			}
			it--;
			if(it -> second >= mass[i].second + 1)
			{
				break;
			}
			if(it == s.begin())
			{
				update(1, 0, q - 1, 0, it -> first, mass[i].second + 1 - it -> second);
			}
			else
			{
				it1 = it;
				it1--;
				update(1, 0, q - 1, it1 -> first + 1, it -> first, mass[i].second + 1 - it -> second);
			}
			s.erase(it);
		}
		s.insert({mass[i].first.second, mass[i].second + 1});
	}
	ans += (q * r - treesum[1]) * (p - 1 - mass[n - 1].first.first);
	cout << ans;
    return 0;
}