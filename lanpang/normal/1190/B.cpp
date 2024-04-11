#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

LL n , a[maxn] , x , s;
set<LL> st;

int main()
{
	int i , j;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		if (st.find(a[i]) != st.end())
		{
			if (x)
			{
				cout << "cslnb\n";
				return 0;
			}
			else x = i;
		}
		else st.insert(a[i]);
	}
	if (x)
	{
		if (a[x])
		{
			a[x]--;
			s++;
		}
		if (st.find(a[x]) != st.end())
		{
			cout << "cslnb\n";
			return 0;
		}
	}
	sort(a+1,a+n+1);
	for (i = 1 ; i <= n ; i++)
		s += a[i]-i+1;
	if (s%2) cout << "sjfnb\n";
	else cout << "cslnb\n";
	return 0;
}