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
int a[N], b[N]; 
int main()
{
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 2; i <= n; i += 2)
	{
		b[i] = a[i / 2];
	}
	for(int i = 1; i <= n; i += 2)
	{
		b[i] = a[n / 2 + (i + 1) / 2];
	} 
	int ans = 0;
	rep(i, 2, n - 1) if(b[i - 1] > b[i] && b[i] < b[i + 1]) ans++;
	printf("%d\n", ans);
	rep(i, 1, n) printf("%d ", b[i]);
	printf("\n");
	return 0;
}