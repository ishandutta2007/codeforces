#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;
pair<ll , ll> b[maxn];
ll a[maxn] , res[maxn];
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i].first , b[i].second = i;
	sort(a , a + n);
	sort(b , b + n);
	reverse(a , a + n);
	for(int i = 0; i < n; i++)
		res[b[i].second] = a[i];
	for(int i = 0; i < n; i++)
		cout << res[i] << " ";
}