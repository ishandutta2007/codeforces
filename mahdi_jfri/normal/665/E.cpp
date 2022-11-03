#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)
const int maxn = 1e6 + 20;
int a[maxn] , ps[maxn] , l[maxn * 31] , r[maxn * 31] , tah = 1 , tl[maxn * 31] , tr[maxn * 31];
void add(int pos , int val , int i = 31)
{
	while(i >= 0)
	{
		if(i < 0)
			return;
		if(!l[pos])
		{
			l[pos] = tah++;
			r[pos] = tah++;
		}
		if(bit(val , i))
			tr[pos]++ , pos = r[pos];
		else
			tl[pos]++ , pos = l[pos];
		i--;
	}
}
ll get(int pos , int val , int k , int i = 31)
{
	ll res = 0;
	while(i >= 0 && l[pos])
	{
		if(bit(val , i))
		{
			if(bit(k , i))
			{
				if(!i)
					res += tl[pos];
				else
					pos = l[pos];
			}
			else
			{
				res += tl[pos];
				if(!i)
					res += tr[pos];
				else
					pos = r[pos];
			}
		}
		else
		{
			if(bit(k , i))
			{
				if(!i)
					res += tr[pos];
				else
					pos = r[pos];
			}
			else
			{
				res += tr[pos];
				if(!i)
					res += tl[pos];
				else
					pos = l[pos];
			}
		}
		i--;
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n , k , res = 0;
	cin >> n >> k;
	add(0 , 0);
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		ps[i] = ps[i - 1] ^ a[i];
		res += get(0 , ps[i] , k);
		add(0 , ps[i]);
	}
	cout << res << endl;
}