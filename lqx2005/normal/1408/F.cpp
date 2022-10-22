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
int n;
vector<int> a, b;
void change(int l, int r)
{
	if(l == r) return;
	int mid = (l + r) / 2;
	change(l, mid);
	change(mid + 1, r);
	rep(i, l, mid) a.push_back(i), b.push_back(i - l + mid + 1);
	return;
}
int main()
{
	scanf("%d", &n);
	int lim = 1;
	while((lim << 1) <= n) lim <<= 1;
	if(lim == n) change(1, n);
	else change(1, lim), change(n - lim + 1, n);
	printf("%d\n", siz(a));
	rep(i, 0, siz(a) - 1) printf("%d %d\n", a[i], b[i]);
	return 0;
	
}