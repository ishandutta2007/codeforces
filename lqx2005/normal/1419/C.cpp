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
const int N = 1e3 + 10;
int t, n, x;
int a[N];
int main()
{
	scanf("%d", &t);
	rep(amo, 1, t)
	{
		scanf("%d%d", &n, &x);
		rep(i, 1, n) scanf("%d", &a[i]);
		int cnt = 0, sum = 0;
		rep(i, 1, n) if(a[i] == x) cnt++;
		rep(i, 1, n) sum += a[i];
		if(n == 2)
		{
			if(cnt == 2) printf("0\n");
			else if(cnt == 1) printf("1\n");
			else if(sum == n * x) printf("1\n");
			else printf("2\n");
			continue;
		}
		if(cnt == n) printf("0\n");
		else if(cnt >= 2) printf("1\n");
		else if(sum  == n * x) printf("1\n");
		else if(cnt == 1) printf("1\n");
		else printf("2\n");
	}
	return 0;
}