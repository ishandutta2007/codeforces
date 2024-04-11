#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define lb(a) ((a)&(-a))
const int maxn = 1e5 + 20;
const int maxk = 12;

ll a[maxn] , fen[maxn][maxk];

void add(int pos , int i , ll val)
{
	for(; pos < maxn; pos += lb(pos))
		fen[pos][i] += val;
}

ll get(int pos , int i)
{
	ll res = 0;
	for(; pos > 0; pos -= lb(pos))
		res += fen[pos][i];
	return res;
}

int main()
{
	int n , k;
	cin >> n >> k;
	k++;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	ll res = 0;
	for(int i = 0; i < n; i++)
		for(int j = 1; j <= k; j++)
		{
			ll x;
			if(j == 1)
				x = 1;
			else
				x = get(a[i] - 1 , j - 1);
			add(a[i] , j , x);
			if(j == k)
				res += x;
		}
	cout << res << endl;
}