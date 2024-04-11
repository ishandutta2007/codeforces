#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, m;
__int128 a[1005], b[1005], c[1005][1005], tmp[1005];
char buf[55];
void getv(__int128& x)
{
	scanf("%s", buf);
	x = 0;
	for(int i = 0; buf[i]; i ++) x = x * 10 + buf[i] - '0';
}
void putv(__int128 x)
{
	int len = 0;
	do {
		buf[len ++] = x % 10 + '0'; x /= 10;
	} while(x > 0);
	reverse(buf, buf + len); buf[len] = 0;
	printf("%s", buf);
}

int fn, fm;
bool da[1005], db[1005];
struct segt
{
	int L;
	__int128 val[2048];
	void build(int len, __int128 arr[])
	{
		L = 1;
		while((1 << L) < len) L ++;
		rep(i, 1 << (L + 1)) val[i] = 0;
		rep(i, len) val[i | 1 << L] = arr[i];
		for(int i = (1 << L) - 1; i >= 1; i --) val[i] = __gcd(val[i << 1], val[i << 1 | 1]);
	}
	void modify(int id)
	{
		id |= 1 << L;
		__int128 dat = val[id] = 0;
		for(; id > 1; id >>= 1) val[id >> 1] = dat = __gcd(dat, val[id ^ 1]);
	}
} sa[1005], sb[1005];
void solve()
{
	scanf("%d%d", &n, &m);
	rep(i, n) getv(a[i]);
	rep(i, m) getv(b[i]);
	fn = n; fm = m;
	rep(i, n) rep(j, m) c[i][j] = __gcd(a[i], b[j]);
	rep(i, n) {
		rep(j, m) tmp[j] = a[i] / c[i][j];
		sa[i].build(m, tmp);
	}
	rep(i, m) {
		rep(j, n) tmp[j] = b[i] / c[j][i];
		sb[i].build(n, tmp);
	}
	rep(i, n) da[i] = false;
	rep(i, m) db[i] = false;

	while(fn > 0 && fm > 0) {
		bool ok = false;
		rep(i, n) if(!da[i] && sa[i].val[1] != 1) {
			da[i] = ok = true;
			rep(j, m) if(!db[j]) sb[j].modify(i);
			fn --; break;
		}
		rep(i, m) if(!db[i] && sb[i].val[1] != 1) {
			db[i] = ok = true;
			rep(j, n) if(!da[j]) sa[j].modify(i);
			fm --; break;
		}
		if(!ok) break;
	}
	if(fn == 0 || fm == 0) {
		printf("NO\n"); return;
	}
	printf("YES\n%d %d\n", fn, fm);
	rep(i, n) if(!da[i]) {
		putv(a[i]); putchar(' ');
	}
	putchar('\n');
	rep(i, m) if(!db[i]) {
		putv(b[i]); putchar(' ');
	}
	putchar('\n');
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}