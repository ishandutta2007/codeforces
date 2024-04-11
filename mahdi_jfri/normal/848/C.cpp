#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int sq = 320;

set<int> pos[maxn];
set<int>::iterator it;

int a[maxn] , nxt[maxn] , n;

ll ps[maxn];

pair<int , int> x[maxn];

void ok(int p)
{
	int R = min(p + sq , n);
	for(int i = p; i < R; i++)
		x[i] = {nxt[i] , nxt[i] - i};
	sort(x + p , x + R);
	ps[p] = x[p].second;
	for(int i = p + 1; i < R; i++)
		ps[i] = ps[i - 1] + x[i].second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> n >> q;

	for(int i = 0; i < n; i++)
		cin >> a[i] , pos[a[i]].insert(i);
	for(int i = 0; i < n; i++)
	{
		it = pos[a[i]].upper_bound(i);
		if(it != pos[a[i]].end())
			nxt[i] = *it;
		else
			nxt[i] = n;
	}

	for(int i = 0; i < n; i += sq)
		ok(i);

	while(q--)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			int p , x;
			cin >> p >> x;
			p--;
			it = pos[a[p]].lower_bound(p);
			if(it != pos[a[p]].begin())
			{
				it--;
				int tmp = *it;
				nxt[tmp] = nxt[p];
				ok(tmp / sq * sq);
			}
			pos[a[p]].erase(p);
			a[p] = x;
			it = pos[a[p]].lower_bound(p);
			if(it != pos[a[p]].end())
			{
				nxt[p] = *it;
				ok(p / sq * sq);
			}
			else
			{
				nxt[p] = n;
				ok(p / sq * sq);
			}
			if(it != pos[a[p]].begin())
			{
				it--;
				int tmp = *it;
				nxt[tmp] = p;
				ok(tmp / sq * sq);
			}
			pos[a[p]].insert(p);
		}
		else
		{
			int l , r;
			cin >> l >> r;
			int R = r;
			ll res = 0;
			l--;
			while(l < r && r % sq)
			{
				r--;
				if(nxt[r] < R)
					res += nxt[r] - r;
			}
			while(l < r && l % sq)
			{
				if(nxt[l] < R)
					res += nxt[l] - l;
				l++;
			}
			for(int i = l; i < r; i += sq)
			{
				pair<int , int> tmp = {R , -1};
				int pos = lower_bound(x + i , x + i + sq , tmp) - x;
				if(pos > i)
					res += ps[pos - 1];
			}
			cout << res << endl;
		}
	}
}