#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 5e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , a[maxn] , f[maxn*2] , s[maxn*2];
LL x , y , mi;

int main ()
{
	cin >> n >> x >> y;
	for (int i = 1 ; i <= n ; i++) 
	{
		scanf("%d",&a[i]);
		s[a[i]]++;
	}
	sort(a+1,a+n+1);
	for (int i = 2 ; i <= 1e6 ; i++)
	{
		if (!f[i])
		{
			LL t = s[i];
			for (int j = i*2 ; j <= 1e6 ; j += i) 
			{
				f[j] = 1;
				t += s[j];
			}
			if (i == 2 || mi > min(x,y)*(LL)(n-t))
			{
				LL ans = 0;
				for (int j = 1 ; j <= n ; j++)
				{
					if (a[j]%i) ans += min(y*(LL)(i-a[j]%i),x);
				}
				if (i == 2) mi = ans;
				else mi = min(mi,ans);
			}
		}
	}
	cout << mi << "\n";
	//system("PAUSE");
	return 0;
}