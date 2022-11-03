#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
ll ps[maxn] , a[maxn] , sum , res;
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i] , sum += a[i];
	if(sum % 3)
	{
		cout << "0\n";
		return 0;
	}
	ll s = 0;
	for(int i = 0; i < n; i++)
	{
		s += a[i];
		if(s == (sum / 3) * 2 && i != n - 1)
			res += ps[i - 1];
		ps[i] = ps[i - 1] + (s == sum / 3);
	}
	cout << res;
}