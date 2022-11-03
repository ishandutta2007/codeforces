#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int a[maxn] , sum[maxn] , b[maxn];
set<int> st , res;
int main()
{
	int k , n;
	cin >> k >> n;
	for(int i = 0; i < k; i++)
		cin >> a[i] , sum[i] = a[i];
	for(int i = 1; i < k; i++)
		sum[i] += sum[i - 1];
	for(int i = 0; i < n; i++)
		cin >> b[i] , st.insert(b[i]);
	sort(sum , sum + k);
	ll mx = *st.rbegin();
//	cout << mx << endl;
	for(int i = k - 1; i >= n - 1; i--)
	{
	//	cout << sum[i] << endl;
		ll x = mx - sum[i];
//		cout << x << endl;
		set<int> stt = st;
		for(int i = 0; i < k; i++)
			stt.erase(x + sum[i]);
		if(stt.empty())
			res.insert(x);
	}
	cout << res.size() << endl;
}