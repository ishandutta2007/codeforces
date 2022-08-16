#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MAXN = 100010;

int n;
int a[MAXN];

int main()
{
	
	scanf("%d", &n);
	for (int i=1; i<=n; ++i)
		scanf("%d", &a[i]);
	sort(a+1, a+n+1);
	int ans = 0;
	for (int i=2; i<n; ++i)
		if (a[1]<a[i]&&a[i]<a[n]) ++ ans;
	cout << ans << endl;
	
	return 0;
}