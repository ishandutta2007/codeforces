#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

const int maxn = 1e6 + 20;

int x , t[maxn];

int get(int l , int r)
{
	l = min(l , maxn - 1);
	r = min(r , maxn - 1);
	return t[r] - t[l];
}

int main()
{
	int n , k;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> x , t[x]++;
	for(int i = 1; i < maxn; i++)
		t[i] += t[i - 1];
	for(int i = maxn - 1; i >= 0; i--)
	{
		bool f = (get(0 , i - 1) == 0);
		for(int j = 0; j < maxn; j += i)
			if(k < i && get(j + k , j + i - 1))
				f = 0;
		if(f)
		{
			cout << i << endl;
			return 0;
		}
	}
}