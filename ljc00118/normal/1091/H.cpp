#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie();
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 2e5 + 5, Max = N - 5;

bitset <N> f[100], wxw;
int sg[N], pri[N], isp[N];
int n, ff, ans, len;

void init_pri() {
	for(register int i = 2; i <= Max; i++) {
		if(!isp[i]) pri[++len] = i;
		for(register int j = 1; j <= len && i * pri[j] <= Max; j++) {
			isp[i * pri[j]] = 1;
			if(i % pri[j] == 0) break;
		}
	}
}

int main() {
	read(n); read(ff); init_pri();
	for(register int i = 1; i <= len; i++) wxw[pri[i]] = 1;
	for(register int i = 1; i <= len; i++) {
		for(register int j = i; j <= len; j++) {
			if(1ll * pri[i] * pri[j] > Max) break;
			wxw[pri[i] * pri[j]] = 1;
		}
	}
	wxw[ff] = 0; f[0] = wxw;
	for(register int i = 1; i <= Max; i++) {
//		if(i % 1000 == 0) fprintf(stderr, "i = %d\n", i);
		while(f[sg[i]][i]) sg[i]++;
		f[sg[i]] |= (wxw << i);
	}
	for(register int i = 1; i <= n; i++) {
		int a, b, c;
		read(a); read(b); read(c);
		ans ^= sg[b - a - 1];
		ans ^= sg[c - b - 1];
	}
	if(ans != 0) printf("Alice\nBob\n");
	else printf("Bob\nAlice\n");
	return 0;
}