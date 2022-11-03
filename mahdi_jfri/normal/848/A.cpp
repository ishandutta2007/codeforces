#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int a[30] , t;
int main()
{
	ll k;
	cin >> k;
	if(!k)
		cout << 'a';
	while(k > 0)
	{
		for(ll i = maxn - 1; i >= 0; i--)
			if(i * (i - 1) / 2 <= k)
			{
				k -= i * (i - 1) / 2;
				a[t] = i;
				t++;
				break;
			}
	}
	for(int i = 0; i < t; i++)
		while(a[i])
		{
			cout << (char)('a' + i);
			a[i]--;
		}
}