#include<bits/stdc++.h>
#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define mpr make_pair
#define x(v) (v).first
#define y(v) (v).second
#define siz(v) (int)(v).size()
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef double db;
const int N = 1e5 + 10;
int t, n;
int a[N];
int main()
{
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	printf("%d\n", (n - 1) / 2);
	rep(i, 1, n)
	{
		if(i % 2) printf("%d ", a[n + 1 - (i + 1) / 2]);
		else printf("%d ", a[i / 2]);
	}
	return 0;
}