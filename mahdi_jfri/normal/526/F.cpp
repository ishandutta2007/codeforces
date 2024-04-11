#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 3e5 + 20;
int a[maxn] , partial_min[maxn] , partial_max[maxn] , t[maxn * 2];

ll f(int s , int e)
{
	if(e - s < 2)
		return 1;
	int m = (s + e) / 2;
	ll res = 0;
	res += f(s , m) + f(m , e);
	partial_min[m] = a[m];
	partial_max[m] = a[m];
	for(int i = m + 1; i < e; i++)
	{
		partial_min[i] = min(partial_min[i - 1] , a[i]);
		partial_max[i] = max(partial_max[i - 1] , a[i]);
	}
	partial_min[m - 1] = a[m - 1];
	partial_max[m - 1] = a[m - 1];
	for(int i = m - 2; i >= s; i--)
	{
		partial_min[i] = min(partial_min[i + 1] , a[i]);
		partial_max[i] = max(partial_max[i + 1] , a[i]);
	}
	// left = min , right = max;
	{
		for(int i = m; i < e; i++)
			t[partial_max[i] - i + maxn]++;
		int mn = a[m - 1] , mx = a[m - 1] , pt_min = e - 1 , pt_max = m;
		for(int i = m - 1; i >= s; i--)
		{
			mn = min(mn , a[i]);
			mx = max(mx , a[i]);
			while(pt_min >= m && partial_min[pt_min] < mn)
			{
				t[partial_max[pt_min] - pt_min + maxn]--;
				pt_min--;
			}
			while(pt_min + 1 < e && partial_min[pt_min + 1] > mn)
			{
				pt_min++;
				t[partial_max[pt_min] - pt_min + maxn]++;
			}
			while(pt_max < e && partial_max[pt_max] < mx)
			{
				t[partial_max[pt_max] - pt_max + maxn]--;
				pt_max++;
			}
			if(pt_min >= m && pt_max < e && pt_max <= pt_min && partial_max[pt_max] > mx && partial_min[pt_min] > mn)
				res += t[mn - i + maxn];
		}
		for(int i = m; i < e; i++)
			t[partial_max[i] - i + maxn] = 0;
	}
	
	// left = max , right = min;

	{
		for(int i = m; i < e; i++)
			t[partial_min[i] + i]++;
		int mn = a[m - 1] , mx = a[m - 1] , pt_min = m , pt_max = e - 1;
		for(int i = m - 1; i >= s; i--)
		{
			mn = min(mn , a[i]);
			mx = max(mx , a[i]);
			while(pt_min < e && partial_min[pt_min] > mn)
			{
				t[partial_min[pt_min] + pt_min]--;
				pt_min++;
			}
			while(pt_max >= m && partial_max[pt_max] > mx)
			{
				t[partial_min[pt_max] + pt_max]--;
				pt_max--;
			}
			while(pt_max + 1 < e && partial_max[pt_max + 1] < mx)
			{
				pt_max++;
				t[partial_min[pt_max] + pt_max]++;
			}
			if(pt_min >= m && pt_max < e && pt_min <= pt_max && partial_max[pt_max] < mx && partial_min[pt_min] < mn)
				res += t[mx + i];
		}
		for(int i = m; i < e; i++)
			t[partial_min[i] + i] = 0;
	}

	// left = max , min
	{
		int mn = a[m - 1] , mx = a[m - 1];
		for(int i = m - 1; i >= s; i--)
		{
			mn = min(mn , a[i]);
			mx = max(mx , a[i]);
			int r = i + mx - mn;
			if(r >= m && r < e && partial_min[r] > mn && partial_max[r] < mx)
				res++;
		}
	}
	// right = max , min
	{
		for(int i = m; i < e; i++)
		{
			int l = i - partial_max[i] + partial_min[i];
			if(l < m && l >= s && partial_min[l] > partial_min[i] && partial_max[l] < partial_max[i])
				res++;
		}
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x , y;
		cin >> x >> y;
		a[--x] = --y;
	}
	cout << f(0 , n) << endl;
}