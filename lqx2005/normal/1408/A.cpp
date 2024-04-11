#include<bits/stdc++.h>
#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define mpr make_pair
#define x(v) (v).first
#define y(v) (v).second
#define siz(v) (int)(v).size()
#define pb push_back
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef double db;
const int N = 1e2 + 10; 
int t, n, a[N], b[N], c[N];
int main()
{
	scanf("%d", &t);
	rep(amo, 1, t)
	{
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n) scanf("%d", &b[i]);
		rep(i, 1, n) scanf("%d", &c[i]);
		int las = a[1];
		printf("%d ", a[1]);
		rep(i, 2, n - 1)
		{
			if(a[i] != las) printf("%d ", a[i]), las = a[i];
			else if(b[i] != las) printf("%d ", b[i]), las = b[i];
			else printf("%d ", c[i]), las = c[i];
		}
		if(a[n] != las && a[n] != a[1]) printf("%d ", a[n]);
		else if(b[n] != las && b[n] != a[1]) printf("%d ", b[n]);
		else if(c[n] != las && c[n] != a[1]) printf("%d ", c[n]);
		printf("\n");
	}
	return 0;
}