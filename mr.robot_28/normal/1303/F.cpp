#include<bits/stdc++.h>
using namespace std;
int n, m, q;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
vector <int> p, rk;
vector <vector <int> > A;
int get(int a)
{
	if(p[a] == a)
	{
		return a;
	}
	else
	{
		return p[a] = get(p[a]);
	}
}
bool unite(int a, int b)
{
	a = get(a);
	b = get(b);
	if(a == b)
	{
		return false;
	}
	if(rk[a] < rk[b])
	{
		swap(a, b);
	}
	p[b] = a;
	rk[a] += rk[b];
	return true;
}
vector <vector <pair <int, int> > > add(2000010), del(2000010);
vector <int> dif(2e6 + 13);
void recalc(vector <pair <int, int> > &ev, int coeff)
{
	for(int i = 0; i < n; i++)
	{
		for(int j =  0; j < m; j++)
		{
			A[i][j] = 0;
		}
	}
	for(int i = 0; i < n * m; i++)
	{
		p[i] = i;
		rk[i] = 1;
	}
	for(int i = 0; i < ev.size(); i++)
	{
		int cur = 1;
		int x = ev[i].first / m;
		int y = ev[i].first % m;
		A[x][y] = 1;
		for(int k = 0; k < 4; k++)
		{
			int nx = dx[k] + x;
			int ny = y + dy[k];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && A[nx][ny] == 1)
			{
				cur -= unite(nx * m + ny, x * m + y);
			}
		}
		dif[ev[i].second] += cur * coeff;
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> q;
	int colors = 1;
	p.resize(n * m);
	rk.resize(n * m);
	A.resize(n, vector <int> (m));
	for(int i = 0; i < q; i++)
	{
		int x, y, c;
		cin >> x >> y >> c;
		x--;
		y--;
		if(A[x][y] == c)
		{
			continue;
		}
		colors = c + 1;
		add[c].push_back({x * m + y, i});
		del[A[x][y]].push_back({x * m + y, i});
		A[x][y] = c;
	}
	for(int x = 0; x < n; x++){
		for(int y = 0; y < m; y++)
		{
			del[A[x][y]].push_back({x * m + y, q});
		}
	}
	for(int i = 0; i < colors; i++)
	{
		reverse(del[i].begin(), del[i].end());
	}
	for(int i = 0; i < colors; i++)
	{
		recalc(add[i], 1);
	}
	for(int i = 0; i < colors; i++)
	{
		recalc(del[i], -1);
	}
	int cur = 1;
	for(int i = 0; i < q; i++)
	{
		cur += dif[i];
		cout << cur << "\n";
	}
	return 0;
}