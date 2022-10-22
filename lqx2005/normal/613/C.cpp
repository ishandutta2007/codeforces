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
const int N = 1e5 + 10;
int n;
int a[26];
char str[N];
int main() {
	scanf("%d", &n);
	int g = 0;
	for(int i = 0; i < n; i++) scanf("%d", &a[i]), g = __gcd(g, a[i]);
	int cnt = 0;
	for(int i = 0; i < n; i++) if(a[i] & 1) cnt++;
	if(cnt > 1) {
		printf("0\n"); 
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < a[i]; j++) printf("%c", (char)(i + 'a'));
		}
		printf("\n");
		return 0;
	}
	for(int i = 0; i < n; i++) a[i] /= g;
	cnt = 0;
	for(int i = 0; i < n; i++) if(a[i] & 1) cnt++;
	int t = g;
	if(cnt > 1) {
		for(int i = 0; i < n; i++) a[i] *= 2;
		t = g;
		g /= 2;
	}
	int tot = 0; 
	for(int i = 0; i < n; i++) tot += a[i];
	int now = 0;
	for(int i = 0; i < n; i++) {
		while(a[i] > 1) {
			a[i] -= 2;
			str[now + 1] = str[tot - now] = 'a' + i;
			now++;
		}
		if(a[i] & 1) str[(tot + 1) / 2] = 'a' + i;
	}
	printf("%d\n", t);
	for(int i = 0; i < g; i++) {
		for(int j = 1; j <= tot; j++) printf("%c", str[j]);
	}
	printf("\n");
	return 0;
}