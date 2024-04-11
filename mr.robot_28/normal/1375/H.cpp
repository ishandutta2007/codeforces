#include<bits/stdc++.h>
using namespace std;
const int t = (1 << 8);
const int maxn = 1 << 12;
const int masq = 1 << 16;
int tree[t * 2 + 3][t + 3][t + 3];
int id[t + 1][maxn + 1];
int sz;
int ai[maxn + 1];
vector <pair <int, int> > mass;
int merge(int a, int b)
{
	if(!a || !b)
	{
		return a + b;
	}
	mass.push_back({a, b});
	return ++sz;
}
int it;
void solve(int v, int l, int r, vector <int> vec)
{
	if(l == r)
	{
		if(vec.size() < 2)
		{
			return;
		}
		tree[v][1][1] = ai[vec[1]];
		return;
	}
	int midd = (r + l) / 2;
	vector <int> vec1(1), vec2(1);
	for(int i = 1; i < vec.size(); i++)
	{
		if(vec[i] <= midd)
		{
			vec1.push_back(vec[i]);
		}
		else
		{
			vec2.push_back(vec[i]);
		}
	}
	solve(v * 2, l, midd, vec1);
	solve(v * 2 + 1, midd + 1, r, vec2);
	for(int i = 1, xl = 1, xr = 1; i < (int)vec.size(); xl += (vec[i] <= midd), xr += (vec[i] > midd), i++){
		for(int j= i - 1, yl = xl - 1, yr = xr - 1; j < vec.size(); j++, yl += (vec[j] <= midd), yr += (vec[j] > midd))
		{
			if(j == i - 1){
				continue;
			}
			tree[v][i][j] = merge(tree[v * 2][xl][yl], tree[v * 2 + 1][xr][yr]);
		}
	}
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    sz = n;
    vector <int> a(n + 1);
    for(int i = 1; i <= n; i++)
    {
    	cin >> a[i];
    	ai[a[i]] = i;
    }
    int cnt = n + 1;
   int dp[t + 3][t + 3][t + 3];
    for(int i = 0; i * t < n; i++)
    {
    	it = i;
    	vector <int> vec(1);
    	int al = i * t + 1;
    	int ar = (i + 1) * t;
    	for(int j = 1; j <= n; j++)
    	{
    		if(a[j] >= al && a[j] <= ar)
    		{
    			vec.push_back(a[j]);
    			id[i][j] = id[i][j - 1] + 1;
    		}
    		else
    		{
    			id[i][j] = id[i][j - 1];
    		}
    	}
    	solve(1, al, ar, vec);
    	for(int k = 1; k < vec.size(); k++){
    		for(int d = 1; d < vec.size(); d++)
    		{
    			dp[i][k][d] = tree[1][k][d];
    		}
    	}
    }
    vector <int> ans(q + 1);
    while(q--)
    {
    	int l, r;
    	cin >> l >> r;
    	ans[q] = 0;
    	for(int i = 0; i * t < n; i++)
    	{
    		ans[q] = merge(ans[q], dp[i][id[i][l - 1] + 1][id[i][r]]);
    	}
    }
    cout << sz << "\n";
    for(int i = 0; i< mass.size(); i++)
    {
    	cout << mass[i].first << " " << mass[i].second << "\n";
    }
    for(int i = ans.size() - 2; i >= 0; i--)
    {
    	cout << ans[i] << " ";
    }
  	return 0;
}