#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1e5+3, MA = 1e4+3, SQ = 600;
int n, q, m, cn[SQ+10][MA], blo[MX], off[SQ];
int a[MX], l, r, x, d;
char s[10];
vi v;
bitset<MA> bs;

bool lucky (int n) {
	while (n) {
		if (n % 10 != 4 && n % 10 != 7)
			return 0;
		n /= 10;
	}
	return 1;
} 

void find () {
	int res = 0, i = l, bl = blo[l], br = blo[r];
	
	if (bl == br) {
		for (int i = l; i <= r; i++)
			res += bs[a[i]+off[bl]];
		printf("%d\n", res);
		return;
	}

	while (blo[i] == bl) {
		res += bs[a[i]+off[bl]];
		i++;
	}
	
	i = r;
	while (blo[i] == br) {
		res += bs[a[i]+off[br]];
		i--;
	}

	i = bl + 1;
	while (i <= br - 1) {
		for (int x = m-1; x >= 0 && v[x] - off[i] >= 0; x--)
			res += cn[i][v[x] - off[i]];
		i++;
	}

	printf("%d\n", res);
} 

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);

	for (int i = 4; i < MA; i++) {
		if (lucky(i)) {
			v.pb(i);
			bs[i] = 1;
		}
	}
	m = v.size();

	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a+i);
		blo[i] = i / SQ;
		cn[blo[i]][a[i]]++;
	}

	while (q--) {
		scanf("%s", s);
		if (s[0] == 'c') {
			scanf("%d%d", &l, &r);
			find();
		} else {
			scanf("%d%d%d", &l, &r, &d);

			int bl = blo[l];
			int br = blo[r];

			if (bl == br) {
				for (int i = l; i <= r; i++) {
					cn[bl][a[i]]--;
					a[i] += d;
					cn[bl][a[i]]++;
				}
				continue;
			}

			int i = l;
			while (blo[i] == bl) {
				cn[bl][a[i]]--;
				a[i] += d;
				cn[bl][a[i]]++;
				i++;
			}

			i = r;
			while (blo[i] == br) {
				cn[br][a[i]]--;
				a[i] += d;
				cn[br][a[i]]++;
				i--;
			}

			i = bl + 1;
			while (i <= br - 1)
				off[i++] += d;
		}
	}

	return 0;
}