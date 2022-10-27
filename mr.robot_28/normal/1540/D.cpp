#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
const int mod = 1e9 + 7;
const int N = 320 * 320;
int n, q;
int b[N];
const int MX = 1e5 + 5;
struct BIT{
	int bit[N];
	void upd(int pos, int v)
	{
		for(;pos <= N; pos += pos&-pos)
		{
			bit[pos] += v;
		}
	}
	int firstAtLeast(int x)
	{
		int pos = 0;
		for(int dif = (1 << 16); dif; dif /= 2)
		{
			if(pos + dif <= N && bit[pos + dif] < x)
			{
				x -= bit[pos += dif];
			}
		}
		return pos + 1;
	}
};
const int BLOCK = 200;
vector <int> incr[N];
int point_upd[N / BLOCK + 10][N];
int range_upd[N / BLOCK + 10][320];
BIT bit;
int query_block(int x, int v)
{
	return point_upd[x][v] + range_upd[x][v / 320];
}
void upd_suf(int x, int pos, int delta)
{
	for(;pos % 320 != 0; ++pos)
	{
		point_upd[x][pos] += delta;
	}
	pos /= 320;
	for(;pos < 320; ++pos)
	{
		range_upd[x][pos] += delta;
	}
}
void rebuild_block(int x)
{
	int L = BLOCK * (x - 1) + 1;
	int R = min(n, BLOCK * x);
	if(!sz(incr[x]))
	{
		incr[x] = vector <int> (R - L + 1, n + 1);
	}
	int bad = 0;
	for(int i = L; i <= R; i++)
	{
		int ind = bit.firstAtLeast(b[i]);
		bit.upd(ind, 1);
		int old_val = incr[x][i - L];
		incr[x][i - L] = ind;
		if(old_val == ind)
		{
			continue;  
		}
		if(ind + 1 == old_val)
		{
			++point_upd[x][ind];
		}
		else if(ind - 1 == old_val)
		{
			--point_upd[x][old_val];
		}
		else
		{
			++bad;
			upd_suf(x, old_val, -1);
			upd_suf(x, ind, 1);
		}
	}
	for(int i : incr[x])
	{
		bit.upd(i, -1);
	}
}
signed main()
{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> b[i];
		b[i] = i - b[i];
	}
	for(int i = 1; i <= N; i++)
	{
		bit.upd(i, 1);
	}
	for(int i = 1; BLOCK * (i - 1) + 1 <= n; i++)
	{
		rebuild_block(i);
	}
	cin >> q;
	while(q--)
	{
		int t;
		cin >> t;
		if(t == 1)
		{
			int pos, x;
			cin >> pos >> x;
			b[pos] = pos - x;
			rebuild_block((pos + BLOCK - 1) / BLOCK);
		}
		else
		{
			int pos;
			cin >> pos;
			int cur = b[pos];
			while(pos < n && pos % BLOCK != 0)
			{
				cur += b[++pos] <= cur;
			}
			while(pos < n)
			{
				int block = pos / BLOCK + 1;
				cur += query_block(block, cur);
				pos += BLOCK;
			}
			cout << cur << "\n";
		}
	}
	return 0;
}