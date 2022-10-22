#include <cstdio>
#include <bitset>
#include <algorithm>
#include <map>
#include <set>
#include <string>
using namespace std;

typedef long long ll;

const int Maxn = 105;
const int Maxm = 100;
const int Maxnim = 205;

struct mask {
	ll fir, sec;
	int len;
	mask() { fir = sec = 0ll; len = 0; }
	void Set(int x, bool val) { 
		if (x < 50)
			if (val == 1) fir |= 1ll << x;
			else fir &= ~(1ll << x);
		else if (val == 1) sec |= 1ll << x - 50;
			 else sec &= ~(1ll << x - 50);
	}
	bool Get(int x) const {
		if (x < 50) return fir & 1ll << x;
		return sec & 1ll << x - 50;
	}
	bool operator <(const mask &b) const {
		if (len != b.len) return len < b.len;
		if (fir != b.fir) return fir < b.fir;
		return sec < b.sec;
	}
};

typedef pair <mask, mask> mm;

int r, n;
bool has[Maxn][3];
bool cantake[Maxn][3];
map <mm, int> M;
int res;

void Fix(mask &m)
{
	while (m.len > 0 && m.Get(m.len - 1) == 0) m.len--;
}

mask getMask(const mask &a, int from, int pos)
{
	mask res;
	if (from) res.len++;
	for (int i = pos; i < a.len; i++) res.Set(res.len++, a.Get(i));
	Fix(res);
	return res;
}

mask getMask(int r1, int r2, int c)
{
	mask res; res.len = r2 - r1;
	for (int i = 0; r1 + i < r2; i++)
		res.Set(i, cantake[r1 + i][c]);
	Fix(res);
	return res;
}

mask getCMask(const mask &a, int pos)
{
	mask res;
	for (int i = 0; i < pos && i < a.len; i++) res.Set(res.len++, a.Get(i));
	Fix(res);
	return res;
}

int getRes(const mask &a, const mask &b)
{
	mm p = a < b? mm(a, b): mm(b, a);
	if (!M.count(p)) {
		bool hasnim[Maxnim] = {};
		for (int i = 0; i < a.len; i++)
			if (a.Get(i)) hasnim[getRes(getCMask(a, i), getCMask(b, i - 1)) ^ getRes(getMask(a, 0, i + 1), getMask(b, 1, i + 2))] = true;
		for (int i = 0; i < b.len; i++)
			if (b.Get(i)) hasnim[getRes(getCMask(a, i - 1), getCMask(b, i)) ^ getRes(getMask(a, 1, i + 2), getMask(b, 0, i + 1))] = true;
		int res = 0;
		while (hasnim[res]) res++;
		M[p] = res;
	}
	return M[p];
}

int main()
{
	scanf("%d %d", &r, &n);
	while (n--) {
		int a, b; scanf("%d %d", &a, &b);
		has[a][b] = true;
	}
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= 2; j++)
			cantake[i][j] = !has[i][j] && (i == 1 || !has[i - 1][3 - j]) && !has[i][3 - j] && (i == r || !has[i + 1][3 - j]);
	int i = 1;
	while (i <= r && !cantake[i][1] && !cantake[i][2]) i++;
	res = i <= r? getRes(getMask(i, r + 1, 1), getMask(i, r + 1, 2)): 0;
	printf("%s\n", res? "WIN": "LOSE");
	return 0;
}