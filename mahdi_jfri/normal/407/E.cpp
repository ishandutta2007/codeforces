#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define back top

const int maxn = 2e5 + 20;
const int inf = 1000 * 1000 * 1000;

int k , a[maxn];

pair<int , int> res;

int handle(int x , int d)
{
	return ((x % d) + d) % d;
}

int Min[maxn * 4] , LazyAdd[maxn * 4];

void puttag(int v , int val)
{
	Min[v] += val;
	LazyAdd[v] += val;
}

void shift(int s , int e , int v)
{
	if(e - s >= 2 && LazyAdd[v] != 0)
	{
		puttag(2 * v , LazyAdd[v]);
		puttag(2 * v + 1 , LazyAdd[v]);
	}

	LazyAdd[v] = 0;
}

void Add(int l , int r , int val , int s , int e , int v)
{
	if(l <= s && e <= r)
	{
		puttag(v , val);
		return;
	}
	if(r <= s || e <= l)
		return;

	shift(s , e , v);

	int m = (s + e) / 2;
	Add(l , r , val , s , m , 2 * v);
	Add(l , r , val , m , e , 2 * v + 1);

	Min[v] = min(Min[2 * v] , Min[2 * v + 1]);
}

int get(int l , int r , int s , int e , int v)
{
	if(r <= s || e <= l)
		return 1e8;

	if(Min[v] > k)
		return 1e8;
	if(e - s < 2)
		return s;

	shift(s , e , v);

	int m = (s + e) / 2;

	int ans = get(l , r , s , m , 2 * v);

	if(ans < maxn)
		return ans;
	else
		return get(l , r , m , e , 2 * v + 1);
}

void solve(vector<int> a , int t)
{
	map<int , int> mp;
	int n = a.size();

	for(int i = 0; i < 4 * n; i++)
		Min[i] = LazyAdd[i] = 0;

	stack<int> mn , mx;
	mn.push(-1);
	mx.push(-1);

	int pt = 0;
	for(int i = 0; i < n; i++)
	{
		// -min
		Add(i , i + 1 , -a[i] , 0 , n , 1);
		while((int)mn.size() > 1 && a[mn.back()] > a[i])
		{
			int R = mn.back() + 1;
			mn.pop();
			int L = mn.back() + 1;

			Add(L , R , a[R - 1] - a[i] , 0 , n , 1);
		}
		mn.push(i);

		// max
		Add(i , i + 1 , a[i] , 0 , n , 1);
		while((int)mx.size() > 1 && a[mx.back()] < a[i])
		{
			int R = mx.back() + 1;
			mx.pop();
			int L = mx.back() + 1;

			Add(L , R , a[i] - a[R - 1] , 0 , n , 1);
		}
		mx.push(i);

		Add(0 , i , -1 , 0 , n , 1);

		pt = max(pt , mp[a[i]]);
		mp[a[i]] = i + 1;

		int ans = get(pt , i + 1 , 0 , n , 1);
		res = max(res , make_pair(i - ans + 1 , -ans - t));
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , d;
	cin >> n >> k >> d;

	for(int i = 0; i < n; i++)
		cin >> a[i] , a[i] += inf;

	if(!d)
	{
		for(int i = 0; i < n; i++)
		{
			int j = i;
			while(j < n && a[j] == a[i])
				j++;

			res = max(res , make_pair(j - i , -i));

			i = j - 1;
		}
	}
	else
		for(int i = 0; i < n; i++)
		{
			int j = i;
			vector<int> tmp;

			while(j < n && handle(a[j] , d) == handle(a[i] , d))
			{
				tmp.pb(a[j] / d);
				j++;
			}

			solve(tmp , i);

			i = j - 1;
		}

	cout << -res.second + 1 << " " << -res.second + res.first << endl;
}