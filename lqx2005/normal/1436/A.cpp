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
const int N = 1e5 + 10;
int a[N];
int main()
{
	int t;
	scanf("%d", &t);
	for(int amo = 1; amo <= t; amo++)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		int sum = 0;
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]), sum += a[i];
		if(sum == m) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}