#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

const int Maxn = 100005;
const int Inf = 2000000000;

int n, k;
int a[Maxn];
char s[15];
int seq[Maxn], slen;

int getInt(const string &s)
{
	if (s == "?") return Inf;
	stringstream ss(s);
	int res; ss >> res;
	return res;
}

bool getBest(int a, int b, int betw)
{
	if (betw == 0) return a == Inf || b == Inf || a < b;
	int l = -(betw - 1) / 2, r = betw / 2;
	if (a != Inf && l <= a) {
		int add = a + 1 - l;
		l += add; r += add;
	}
	if (b != Inf && b <= r) {
		int sub = r + 1 - b;
		l -= sub; r -= sub;
	}
	if (a != Inf && l <= a || b != Inf && b <= r)
		return false;
	for (int i = l; i <= r; i++)
		seq[slen++] = i;
	return true;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%s", s); a[i] = getInt(s);
	}
	for (int i = 0; i < k; i++) {
		slen = 0;
		int lst = Inf;
		int cnt = 0;
		for (int j = i; j < n; j += k)
			if (a[j] == Inf) cnt++;
			else {
				if (!getBest(lst, a[j], cnt)) { printf("Incorrect sequence\n"); return 0; }
				seq[slen++] = a[j];
				lst = a[j];
				cnt = 0;
			}
		if (!getBest(lst, Inf, cnt)) { printf("Incorrect sequence\n"); return 0; }
		int pnt = 0;
		for (int j = i; j < n; j += k) {
			a[j] = seq[pnt++];
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d%c", a[i], i + 1 < n? ' ': '\n');
	return 0;
}