#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define e1 first
#define e2 second
#define pb push_back
#define boost ios_base::sync_with_stdio(false)
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair <int, int> BONG;
typedef pair <BONG, BONG> LONG;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll INF = 1e18+3;
#define maxn 1000100
ll a[maxn];
int n;
int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) scanf("%I64d", &a[i]);
	sort(a+1, a+n+1);
	ll wyn = 0;
	ll para = 0;
	for (int i=n; i>0; --i)
	{
		if (a[i] == a[i-1])
		{
			if (para != 0) wyn += para * a[i], para = 0;
			else para = a[i];
			i -= 1;
		}
		else
		{
			a[i]--;
			if (a[i] == a[i-1])
			{
				if (para != 0) wyn += para * a[i], para = 0;
				else para = a[i];
				i -= 1;
			}
		}
	}
	printf("%I64d", wyn);
}