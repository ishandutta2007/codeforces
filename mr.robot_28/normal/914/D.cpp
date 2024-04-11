#include<bits/stdc++.h>
using namespace std;
vector <int> A, t;
void build(int v, int l, int r)
{
	if(l == r){
		t[v] = A[l];
	}
	else
	{
		build(v * 2, l, (r + l) / 2);
		build(v * 2 + 1, (r + l) / 2 + 1, r);
		t[v] = __gcd(t[v * 2], t[v * 2 + 1]);
	}
}
void update(int v, int l, int r, int ind)
{
	if(l == r)
	{
		t[v] = A[ind];
		return;
	}
	if(ind <= (r + l) / 2)
	{
		update(v * 2, l, (r + l) / 2, ind);
		t[v] = __gcd(t[v * 2], t[v * 2 + 1]);
	}
	else
	{
		update(v * 2 + 1, (r + l) / 2 + 1, r, ind);
		t[v] = __gcd(t[v * 2], t[v * 2 + 1]);
	}
}
int ans(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		return t[v];
	}
	else
	{
		int k = 0;
		if(al <= (r + l) / 2 && ar >= l)
		{
			k = __gcd(k, ans(v * 2, l, (r + l) / 2, al, ar));
		}
		if(al <= r && ar > (r + l) / 2){
			k = __gcd(k, ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar));
		}
		return k;
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	A.resize(n);
	t.resize(4 * n);
	int t = sqrt(n) + 1;
	vector <int> SQRT(t);
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i < t; i++)
	{
		for(int j = i * t; j < min(t + i * t, n); j++)
		{
			if(j == i * t)
			{
				SQRT[i] = A[j];
			}
			else
			{
				SQRT[i] = __gcd(A[j], SQRT[i]);
			}
		}
	}
	int q;
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			int l, r, x;
			cin >> l >> r >> x;
			l--;
			r--;
			int l1 = t + l - l % t;
			int r1 = r - r % t;
			int cnt = 0;
			if(l1 > r1){
				for(int j = l; j <= r; j++){
					if(A[j] % x != 0)
					{
						cnt++;
					}
				}
			}
			else
			{
			for(int j = l; j < l1; j++)
			{
				if(A[j] % x != 0)
				{
					cnt++;
				}
			}
			for(int j = r1; j <= r; j++)
			{
				if(A[j] % x != 0)
				{
					cnt++;
				}
			}
			for(int j = l1 / t; j < r / t; j++)
			{
				if(SQRT[j] % x != 0)
				{
					if(cnt == 1)
					{
						cnt++;
						break;
					}
					for(int p = j * t; p < min(j * t + t, n); p++)
					{
						if(A[p] % x != 0)
						{
							cnt++;
						}
					}
				}
				if(cnt >= 2){
					break;
				}
			}
			}
			if(cnt <= 1){
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
		else
		{
			int ind, y;
			cin >> ind >> y;
			ind--;
			int p = ind / t;
			A[ind] = y;
			update(1, 0, n - 1, ind);
			SQRT[p] = ans(1, 0, n - 1, p * t, p * t + t - 1);
		}
	}
    return 0;
}