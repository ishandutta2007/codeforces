#include<bits/stdc++.h>

using namespace std;

#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()
#define x first
#define y second
#define mp make_pair
#define pb push_back

template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> par;
typedef long long LL;
typedef unsigned long long uLL;
typedef double db;
const int N = 2e5 + 10;
int T, n;
char s[N];
void work() {
	scanf("%d%s", &n, s + 1);
	int c0 = 0, c1 = 0;
	for(int i = 1; i <= n; i++) {
		if(s[i] == '1') c0++;
		else c1++;
	}
	if((c0 & 1) || (c1 & 1)) return printf("NO\n"), void();
	int n0 = 0, n1 = 0, now = 0;
	for(int i = 1; i <= n; i++) {
		if(s[i] == '1') {
			n0++;
			if(n0 <= c0 / 2) now++;
			else now--;
		} else {
			n1++;
			if(n1 & 1) now--;
			else now++;
		}
		if(now < 0) return printf("NO\n"), void();
	}
	printf("YES\n");
	n0 = n1 = 0;
	for(int i = 1; i <= n; i++) {
		if(s[i] == '1') {
			n0++;
			if(n0 <= c0 / 2) printf("(");
			else printf(")");
		} else {
			n1++;
			if(n1 & 1) printf(")");
			else printf("(");
		}
	}
	printf("\n");
	n0 = n1 = 0;
	for(int i = 1; i <= n; i++) {
		if(s[i] == '1') {
			n0++;
			if(n0 <= c0 / 2) printf("(");
			else printf(")");
		} else {
			n1++;
			if(n1 & 1) printf("(");
			else printf(")");
		}
	}
	printf("\n");
	return;
}

int main() {
	scanf("%d", &T);
	for(; T--; ) work();
	return 0;
}