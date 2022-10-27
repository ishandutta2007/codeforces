#include<bits/stdc++.h>
 
using namespace std;
long long min(long long a, long long b)
{
	if(a < b)
	{
		return a;
	}
	return b;
}
vector <long long> tree, upd;
void push(int v, int l, int r)
{
	tree[v * 2] += upd[v];
	tree[v * 2 + 1] += upd[v];
	upd[v * 2] += upd[v];
	upd[v * 2 + 1] += upd[v];
	upd[v] = 0;
}
void update(int v, int l, int r, int al, int ar, long long val)
{
	if(l >= al && r <= ar)
	{
		tree[v] += val;
		upd[v] += val;
	}
	else if(l <= ar && r >= al)
	{
		push(v, l, r);
		update(v * 2, l, (r + l) / 2, al, ar, val);
		update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
		tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
	}
}
void update1(int v, int l, int r, int ind, long long val)
{
	if(l == r)
	{
		tree[v] = val;
		return;
	}
	push(v, l, r);
	if(ind <= (r + l) / 2)
	{
		update1(v * 2, l, (r + l) / 2, ind, val);
	}
	else
	{
		update1(v * 2 + 1, (r + l) / 2 + 1, r, ind, val);
	}
	tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
}
long long ans(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		return tree[v];
	}
	else if(l <= ar && r >=  al)
	{
		push(v, l, r);
		return min(ans(v * 2, l, (r + l) /2 , al, ar), ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar));
	}
	return 1e18;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	long long r1, r2, r3, d;
	cin >> n >> r1 >> r2 >> r3 >> d;
	vector <int> a(n);
	swap(r2, r3);
	tree.resize(4 * n, 1e18);
	upd.resize(4 * n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	long long val1 = 0;
	vector <long long> pref(n);
	long long val = 0;
	for(int i = 0; i < n; i++)
	{
		long long sum1, sum2;
		sum1 = min((a[i] + 1) * r1 + min(r1, min(r2, r3)), a[i] * r2 + r1 + min(r1, min(r2, r3)));
		sum1 = min(sum1, r3 + min(r1, min(r2, r3)));
		sum2 = min((a[i]) * r1 + r2, (a[i] + 1) * r2);
		if(i == n - 1)
		{
			val1 = min(val1 + sum2, val1 + sum1 + 2 * d);
			val1 = min(val1, val + min(sum1, sum2));
			if(i  >1)
			{
				pref[i - 2] += - min(sum1 + d, sum2);
				pref[i - 2] += min(sum1 + 2 * d, sum2);
			}
			if(i != 0)
			{
				pref[i - 1] += min(sum1 + d, sum2);
			}
		}
		else
		{
			long long k = sum2;
			if(i != 0)
			{
				k = min(sum1, sum2);
			}
			long long val2 = val;
			if(i != 0)
			{
				val2 += min(sum1, sum2);
			}
			pref[i] += min(val1, val) + sum1;
			if(i == 0)
			{
				val2 = min(val1, val) + sum1;
			}
			val2 = min(val2, min(val1, val) + sum1);
			if(i != 0)
			{
				pref[i - 1] -= min(val1, val) + sum1;
			}
			val1 += sum2;
			val1 = min(val1, val + k);
			val1 += d;
			pref[i] += 3 * d;
			val2 += 3 * d;
			if(i != 0)
			{
				pref[i - 1] += min(sum1, sum2); 
			}
			val = val2;
		}
	}
	long long sum = 0;
	for(int i = n - 2; i >= 0; i--)
	{
		sum += pref[i];
		
		val1 = min(val1, sum - (n - i - 1) * d);
	}
	cout << val1;
	return 0;
}