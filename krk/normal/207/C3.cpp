#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 100005;
const int Maxm = 20;
const int pw1 = 37;
const int mod1 = 1000000007;
const int mod2 = 1000000009;

ii pw[Maxm];
int lg[Maxn];
int P[Maxn][Maxm];
ii hsh[Maxn][Maxm];
int n;
int a[Maxn], b[Maxn];
char c[Maxn];
int sa[Maxn], rank[Maxn];
int BIT1[Maxn], BIT2[Maxn];
int L1[Maxn], L2[Maxn];
int lef[Maxn], rig[Maxn];
int n1, n2;
ll res;

bool Less(int a, int b)
{
	for (int i = Maxm - 1; i >= 0; i--)
		if (1 << i <= L2[a] && 1 << i <= L2[b] && hsh[a][i].first == hsh[b][i].first && hsh[a][i].second == hsh[b][i].second)
			a = P[a][i], b = P[b][i];
	if (a == 1 && b == 1) return false;
	if (a == 1) return true;
	if (b == 1) return false;
	return hsh[a][0].first < hsh[b][0].first;
}

void Insert(int BIT[], int x, int val)
{
	for (int i = x; i < Maxn; i += i & -i)
		BIT[i] += val;
}

int Get(int BIT[], int x)
{
	int res = 0;
	for (int i = x; i > 0; i -= i & -i)
		res += BIT[i];
	return res;
}

int goUp(int x, int lvl)
{
	while (lvl) {
		x = P[x][lg[lvl & -lvl]];
		lvl -= lvl & -lvl;
	}
	return x;
}

int main()
{
	pw[0] = ii(pw1, pw1);
	for (int i = 1; i < Maxm; i++)
		pw[i] = ii(ll(pw[i - 1].first) * ll(pw[i - 1].first) % ll(mod1), ll(pw[i - 1].second) * ll(pw[i - 1].second) % ll(mod2));
	lg[1] = 0;
	for (int i = 2; i < Maxn; i++) lg[i] = lg[i >> 1] + 1;
	n1 = n2 = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %c", &a[i], &b[i], &c[i]);
		if (a[i] == 2) {
			int v = b[i]; n2++; L2[n2] = L2[v] + 1;
			P[n2][0] = v; hsh[n2][0] = ii(c[i] - 'a' + 1, c[i] - 'a' + 1);
			for (int i = 1; i < Maxm; i++) {
				P[n2][i] = P[P[n2][i - 1]][i - 1];
				hsh[n2][i] = ii((ll(hsh[P[n2][i - 1]][i - 1].first) * ll(pw[i - 1].first) + ll(hsh[n2][i - 1].first)) % ll(mod1),
								(ll(hsh[P[n2][i - 1]][i - 1].second) * ll(pw[i - 1].second) + ll(hsh[n2][i - 1].second)) % ll(mod2));
			}
		}
	}
	for (int i = 1; i <= n2; i++) sa[i] = i;
	sort(sa + 1, sa + n2 + 1, Less);
	for (int i = 1; i <= n2; i++) rank[sa[i]] = i;
	res++; lef[1] = 1; rig[1] = n2; n2 = 1;
	Insert(BIT2, 1, 1); Insert(BIT1, rank[1], 1);
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			int v = b[i]; n1++; L1[n1] = L1[v] + 1;
			int nd = c[i] - 'a' + 1;
			if (lef[v] > rig[v]) { lef[n1] = lef[v]; rig[n1] = rig[v]; }
			else {
				if (nd < hsh[goUp(sa[lef[v]], L1[n1] - 1)][0].first) rig[n1] = lef[v] - 1;
				else {
					int l = lef[v], r = rig[v];
					int res = l;
					while (l <= r) {
						int mid = l + r >> 1;
						if (hsh[goUp(sa[mid], L1[n1] - 1)][0].first <= nd) { res = mid; l = mid + 1; }
						else r = mid - 1;
					}
					rig[n1] = res;
				} 
				if (hsh[goUp(sa[rig[v]], L1[n1] - 1)][0].first < nd) lef[n1] = rig[v] + 1;
				else {
					int l = lef[v], r = rig[v];
					int res = r;
					while (l <= r) {
						int mid = l + r >> 1;
						if (nd <= hsh[goUp(sa[mid], L1[n1] - 1)][0].first) { res = mid; r = mid - 1; }
						else l = mid + 1;
					}
					lef[n1] = res;
				}
				if (lef[n1] <= rig[n1]) {
					res += Get(BIT1, rig[n1]) - Get(BIT1, lef[n1] - 1);
					Insert(BIT2, lef[n1], 1); Insert(BIT2, rig[n1] + 1, -1);
				}
			}
		} else {
			n2++;
			res += Get(BIT2, rank[n2]);
			Insert(BIT1, rank[n2], 1);
		}
		printf("%I64d\n", res);
	}
	return 0;
}