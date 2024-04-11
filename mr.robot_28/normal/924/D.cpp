#include<bits/stdc++.h>

using namespace std;
bool cmp(pair <pair <int, int>, int> a, pair <pair <int, int>, int> b)
{
	return 1LL * a.first.first * b.first.second <1LL * a.first.second * b.first.first;
}
const double eps = 1e-9;
vector <int> tree;
void update(int v, int l, int r, int ind)
{
	tree[v]++;
	if(l == r)
	{
		return;
	}
	if(ind <= (r + l) / 2)
	{
		update(v * 2, l, (r + l) / 2, ind);
	}
	else
	{
		update(v * 2 + 1, (r + l) / 2 + 1, r, ind);
	}
}
int ans(int v, int l, int r, int al, int ar){
	if(l >= al && r <= ar){
		return tree[v];
	}
	else if(l <= ar && r >= al)
	{
		return ans(v * 2, l, (r + l) / 2, al, ar) + ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar); 
	}
	return 0;
}
signed main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n, w;
	cin >> n >> w;
	tree.resize(4 * n);
	vector <pair <pair <int, int>, int> > mass, uniq;
	int cnt3 = 0, cnt4 = 0;
	vector <int> type(n);
	for(int i = 0; i < n; i++)
	{
		int x, v;
		cin >> x >> v;
		if(v < 0)
		{
			type[i] = 1;
		}
		else
		{
			type[i] = 2;
		}
		mass.push_back({{abs(x), abs(v - w)}, i});
		uniq.push_back({{abs(x), abs(v + w)}, i});
	}
	sort(uniq.begin(), uniq.end(), cmp);
	vector <int> ind(n);
	int c = 0;
	for(int i = 0; i < n; i++)
	{
		int j = i;
		while(j < n && 1LL * uniq[j].first.first * uniq[i].first.second == 1LL * uniq[j].first.second * uniq[i].first.first)
		{
			ind[uniq[j].second] = c;
			j++;
		}
		c++;
		i =j - 1;
	}
	sort(mass.begin(), mass.end(), cmp);
	long long sum = 0;
	for(int i = 0; i < mass.size(); i++){
		int j = i;
		int c1 = 0, c2 = 0;
		while(j < mass.size() && 1LL * mass[j].first.first * mass[i].first.second == 1LL * mass[j].first.second * mass[i].first.first)
		{
				c1++;
				sum += ans(1, 0, n - 1, ind[mass[j].second], n - 1);
			j++;
		}
		while(i < j)
		{
				update(1, 0, n - 1, ind[mass[i].second]);
			i++;
		}
		sum += 1LL * c1 * (c1 - 1) / 2;
//		cout << mass[i - 1].first.first << " " << mass[i - 1].first.second << " " << sum << "\n";
		i = j - 1;
	}
	for(int i = 0; i < 4 * n; i++)
	{
		tree[i] = 0;
	}
	cout << sum;
	return 0;
}