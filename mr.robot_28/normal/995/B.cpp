#include<bits/stdc++.h>
using namespace std;
#define int long long
const int const1 =998244353;
vector <int> tree;
void update(int v, int l, int r, int ind, int val)
{
	tree[v] += val;
	if(l == r)
	{
		return;
	}
	if(ind <= (r + l) / 2)
	{
		update(v * 2, l, (r + l) / 2, ind, val);
	}
	else
	{
		update(v * 2 + 1, (r + l) / 2 + 1, r, ind, val);
	}
}
int ans(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		return tree[v];
	}
	else if(l <= ar && r >= al)
	{
		return ans(v * 2, l, (r + l) / 2, al, ar) + ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
	}
	else
	{
		return 0;
	}
}
signed main() {
  	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  	cout.tie(NULL);
  	int n;
  	cin >> n;
  	vector <int> a(n * 2);
  	vector <int> st(n, -1);
  	for(int i = 0; i < n * 2; i++)
  	{
  		cin >> a[i];
  		a[i]--;
  	}
  	tree.resize(n * 8, 0);
  	int sum = 0;
  	for(int i = 0; i < n * 2; i++)
  	{
  		if(st[a[i]] == -1)
  		{
  			st[a[i]] = i;
  		}
  		else{
  			if(st[a[i]] < i - 1)
  			{
  				sum -= ans(1, 0, n * 2 - 1, st[a[i]] + 1, i - 1);
  			}
  			sum += i - st[a[i]] - 1;
  			update(1, 0, n * 2 - 1, st[a[i]], -1);
  			update(1, 0, n * 2  - 1, i, 1);
  		}
  	}
  	cout << sum;
    return 0;
}