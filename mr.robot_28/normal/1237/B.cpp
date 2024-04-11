#include <bits/stdc++.h>
using namespace std;
vector <int> t;
void update(int v, int l, int r, int pos)
{
	if(l == r)
	{
		t[v]++;
		return;
	}
	t[v]++;
	if(pos <= (r + l) / 2)
	{
		update(v * 2, l, (r + l) / 2, pos);
	}
	else
	{
		update(v * 2 + 1, (r + l) / 2 + 1, r, pos);
	}
}
int ans(int v, int l, int r, int al, int ar)
{
	if(l > r)
	{
		return 0;
	}
	if(l >= al && r <= ar)
	{
		return t[v];
	}
	else if(l > ar || r < al)
	{
		return 0;
	}
	else
	{
		return ans(v * 2, l, (r + l) / 2, al, ar) + ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
	}
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> A(n);
	vector <int> P(n);
	t.resize(4 * n, 0);
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		P[x - 1] = i;
	}
	for(int i = 0; i < n; i++)
	{
		int y;
		cin >> y;
		A[P[y - 1]] = i;
	}
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		if(ans(1, 0, n - 1, A[i] + 1, n - 1))
		{
			cnt++;
		}
		update(1, 0, n - 1, A[i]);
	}
	cout << cnt;
  	return 0;
}