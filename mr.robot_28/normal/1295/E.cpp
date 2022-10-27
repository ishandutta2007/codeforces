#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <int> treemin;
vector <int> upd;
void push(int v, int l, int r)
{
	treemin[v * 2] += upd[v];
	treemin[v * 2 + 1] += upd[v];
	upd[v * 2] += upd[v];
	upd[v * 2 + 1] += upd[v];
	upd[v] = 0;
}
void update(int v, int l, int r, int al, int ar, int val)
{
	if(l >= al && r <= ar){
		treemin[v] += val;
		upd[v] += val;
	}
	else if(l <= ar && r >= al)
	{
		push(v, l, r);
		update(v * 2, l, (r + l) / 2, al, ar, val);
		update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
		treemin[v] = min(treemin[v * 2], treemin[v * 2 + 1]);
	}
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    upd.resize(4 * n, 0);
    treemin.resize(4 * n, 0);
    vector <int> p(n), a(n);
    for(int i = 0; i < n; i++)
    {
    	cin >> p[i];
    	p[i]--;
    }
    for(int i = 0; i < n; i++)
    {
    	cin >> a[i];
    }
    for(int i = n - 1; i >= 0; i--)
    {
    	update(1, 0, n - 1, p[i], n - 1, a[i]);
    }
    int ans = 1e18;
    ans = min(ans, a[0]);
    ans = min(ans, a[n - 1]);
    for(int i = 0; i < n - 1; i++)
    {
    	update(1, 0, n - 1, p[i], n - 1, -a[i]);
    	if(p[i] != 0)
    	{
    		update(1, 0, n - 1, 0, p[i] - 1, a[i]);
    	}
    	ans = min(ans, treemin[1]);
    }
    cout << ans;
    return 0;
}