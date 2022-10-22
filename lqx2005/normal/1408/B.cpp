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
const int N = 110;
int t, n, k;
int a[N];
int main()
{
	scanf("%d", &t);
	rep(amo, 1, t)
	{
		scanf("%d%d", &n, &k);
		rep(i, 1, n) scanf("%d", &a[i]);
		int flag = 0;
		rep(i, 1, n) if(a[i] != 0) flag = 1;
		if(!flag) 
		{
			printf("0\n");
			continue;
		}
		int m = 0;
		rep(i, 2, n) if(a[i - 1] < a[i]) m++;
		if(k == 1) 
		{
			if(m > 0) printf("-1\n");
			else printf("1\n");
		}
		else 
		{
			if(m == 0) printf("1\n");
			else printf("%d\n", (m + k - 2) / (k - 1));
		}
	}
	return 0;
}