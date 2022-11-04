#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
const int maxn = 1e6+10;
const int inf = 0x3f3f3f3f;
const LL mod = 1e9+7;

LL n , a[maxn] , ans , b[maxn] , c[maxn] , d[maxn] , p , s[maxn] , g , tp , bt;
set<LL> st;

int main()
{
	LL i , j , k;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
		scanf("%I64d",&a[i]);
	sort(a+1,a+n+1);
	/*for (i = 1 ; i <= n ; i++)
		cout << a[i] << " ";
	cout << "\n";*/ 
	for (i = 1 ; i <= n ; i++)
		b[i] = b[i-1]+a[i];
	for (i = n ; i >= 1 ; i--)
		s[i] = s[i+1]+a[i];
	for (i = 1 ; i <= n ; i++)
	{
		j = n-i+1;
		if (j < n) c[j] = c[j+1];
		else c[j] = mod;
		p = upper_bound(a+1,a+i,j+1)-a;
		if (p <= i-1) g = b[p-1]+(i-p)*(j+1);
		else g = b[i-1];
		c[j] = min(c[j],j*(j+1)+g-s[i]);
		//cout << j << " " << c[j] << "\n";
		/*if (c[j] < a[i])
		{
			cout << "-1\n";
			return 0;
		}*/ 
	}
	for (i = n-1 ; i >= 0 ; i--)
	{
		j = n-i+1;
		p = upper_bound(a+1,a+i+1,j-1)-a;
		if (p <= i) g = b[p-1]+(i-p+1)*(j-1);
		else g = b[i];
		d[j] = max(d[j-1],s[i+1]-(j-2)*(j-1)-g);
		//cout << j << " " << d[j] << "\n";
		/*if (j < d[j])
		{
			printf("-1\n");
			return 0;
		}*/
	}
	for (i = n ; i >= 0 ; i--)
	{
		j = n-i+1;
		p = upper_bound(a+1,a+i+1,j)-a;
		if (p <= i) g = b[p-1]+(i-p+1)*j;
		else g = b[i];
		tp = j*(j-1)+g-s[i+1];
		if (i < n) tp = min(tp,a[i+1]);
		if (j <= n) tp = min(tp,c[j]); 
		bt = max(d[j],a[i]);
		for (k = bt ; k <= tp ; k++)
			if ((k%2) == (b[n]%2)) st.insert(k);
		//cout << j << " " << bt << " " << tp << "\n";
	}
	if (st.empty()) 
	{
		cout << "-1\n";
		return 0;
	}
	while (!st.empty())
	{
		printf("%I64d ",(*st.begin()));
		st.erase(st.begin());
	}
	cout << "\n";
	return 0;
}