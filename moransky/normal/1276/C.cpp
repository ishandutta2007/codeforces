#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 4e5 + 5;

int n, a[N], x, y, mx, t, b[N], tot, c[N], sum[N];

map<int, int> cnt;

set<int> s[N];
set<PII> st;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		cnt[a[i]]++;
		mx = max(mx, cnt[a[i]]);
	}
	for (auto i: cnt) {
		
		st.insert(mp(i.se, i.fi));
		for (int j = 1; j <= i.se; j++)
			sum[j] ++;
	}
	for (int i = 1; i <= n; i++) sum[i] += sum[i - 1];
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i && i * j <= n; j++) {
			//cout << " cho " << i << " " << j << " " << sum[j] << endl;
			if (sum[j] >= i * j && i * j >= t)
				t = i * j, x = i, y = j;
		}
	}
	printf("%d\n", t);
	printf("%d %d\n", x, y);
	vector<vector<int> > a;
	a.resize(x + 1);
 	for (int i = 0; i <= x; i++)
 		a[i].resize(y + 1);
 	for (int i = 1; i <= x; i++) {
 		for (int j = 1; j <= y; j++) {
 			s[j].insert(i);
 		}
 	}
	set<PII>::iterator it = st.end();  --it;
	int i = 1, j = 1, now = 1;
	int rest = t;
	bool o = 0;
	while (1) {
		int w = it -> se, c = min(it -> fi, min(y, rest));
		rest -= c;
		//cout << c << " " << i << " " << j << " caonimade\n";
		
		while (c--) {
			a[i][j] = w;
			//cout << i << " " << j << " " << c << " " << w << endl;
			++i, ++j;
			if (i == x + 1) i = 1;
			if (j == y + 1) j = 1;
			if (a[i][j]) i++;
			if (i == x + 1) i = 1;
//			if (j > y || i > x) {
//				if (!o) {
//					j = 1, ++now, i = now;
//					if (now == x) o = 1, now = 2;//, cout << " oooo\n";
//				} else {
//					j = now, i = 1;
//				//	cout << " rinima\n";
//					++now;
//				}
//			}
		}
		//cout << rest << " ??\n";
		if (rest == 0) break;
		--it;
	}
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			printf("%d ", a[i][j]);
		}
		puts("");
	}
	return 0;
}