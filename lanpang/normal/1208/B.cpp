#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , a[2010] , ans;
set<int> st;

int main()
{
	int i , j , f;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
		cin >> a[i];
	for (i = 0 ; i <= n ; i++)
	{
		st.clear();
		f = 0;
		for (j = 1 ; j <= i ; j++)
		{
			if (st.find(a[j]) != st.end())
			{
				f = 1;
				break;
			}
			else st.insert(a[j]);
		}
		if (f) break;
		for (j = n ; j > i ; j--)
		{
			if (st.find(a[j]) != st.end()) break;
			else st.insert(a[j]);
		}
		ans = max(ans,i+n-j);
	}
	cout << n-ans << "\n";
	return 0;
}