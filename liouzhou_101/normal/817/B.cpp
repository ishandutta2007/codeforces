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
map<ld, ll> F;

int main()
{
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i)
		scanf("%d", &a[i]);
	
	map<int, ll> L, R;
	for (int i = 2; i <= n; ++ i)
		R[a[i]] ++;
	for (int i = 2; i < n; ++ i)
	{
		if (--R[a[i]] == 0)
			R.erase(a[i]);
		L[a[i-1]] ++;
		auto x = L.begin();
		auto y = R.begin();
		F[log(x->X)+log(y->X)+log(a[i])] += x->Y*y->Y;
	}
	cout << F.begin()->Y << endl;
	
	return 0;
}