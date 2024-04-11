#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define lb(a) ((a)&(-a))
const int maxn = 2e5 + 20;

int a[maxn] , fen[maxn][2] , b[maxn];

void add(int pos , int type , int val)
{
	for(pos++; pos < maxn; pos += lb(pos))
		fen[pos][type] += val;
}

int get(int pos , int type)
{
	int res = 0;
	for(pos++; pos > 0; pos -= lb(pos))
		res += fen[pos][type];
	return res;
}

int main()
{
	int n;
	ll k;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> a[i] , b[i] = a[i];
	sort(b , b + n);
	for(int i = 0; i < n; i++)
		a[i] = lower_bound(b , b + n , a[i]) - b;
	ll ans = 0 , inv = 0 , R = 1;
	for(int i = n - 1; i >= 1; i--)
	{
		inv += get(a[i] - 1 , 1);
		add(a[i] , 1 , 1);
	}
	for(int i = 0; i < n; i++)
	{
		inv += get(a[i] - 1 , 1);
		inv += get(maxn - 2 , 0) - get(a[i] , 0);
		add(a[i] , 0 , 1);
		while(R <= i || (R < n && inv > k))
		{
			inv -= get(a[R] - 1 , 1);
			inv -= get(maxn - 2 , 0) - get(a[R] , 0);
			add(a[R] , 1 , -1);
			R++;
		}
		ans += n - R;
	}
	cout << ans << endl;
}