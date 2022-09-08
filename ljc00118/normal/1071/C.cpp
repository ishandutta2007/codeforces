#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define For(i, a, b) for(register int i = a; i <= b; i++)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
    while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
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

const int N = 1e5 + 5;

vector <int> t[N];
int l[N], r[N], vis[N], ans, tot, n;
int mid[N], a[N];

int main() {
	cin >> n;
	for(register int i = 1; i <= n; i++) read(a[i]);
	for(register int i = 1, end = min(n / 3, 5000); i <= end; i++) {
		for(register int j = i + 1; j <= n - i; j++) {
			if(a[j - i] == 1 && a[j] == 1 && a[j + i] == 1) {
				a[j - i] ^= 1;
				a[j] ^= 1;
				a[j + i] ^= 1;
				l[++tot] = j - i;
				mid[tot] = j;
				r[tot] = j + i;
			}
		}
	}
	for(register int i = 1; i <= n; i++) {
		if(a[i] == 1) {
			t[i % 3].push_back(i);
		}
	}
	for(register int qwq = 0; qwq < 3; qwq++) {
		int len = t[qwq].size();
		for(register int i = 0, end = len / 2 - 1; i <= end; i++) {
			int ll, rr;
			ll = t[qwq][i] + (t[qwq][len - i - 1] - t[qwq][i]) / 3;
			rr = t[qwq][len - i - 1] - (t[qwq][len - i - 1]  - t[qwq][i]) / 3;
			l[++tot] = t[qwq][i];
			mid[tot] = ll;
			r[tot] = rr;
			l[++tot] = ll;
			mid[tot] = rr;
			r[tot] = t[qwq][len - i - 1];
		}
		if(len % 2 == 1) {
			ans = t[qwq][len / 2];
			if(!((ans > 3 && ans <= (n - 3)) || (ans > 6) || (ans <= (n - 6)))) {puts("NO"); return 0;}
			if(ans > 6) {
				tot++; l[tot] = ans - 6; mid[tot] = ans - 3; r[tot] = ans;
				tot++; l[tot] = ans - 6; mid[tot] = ans - 5; r[tot] = ans - 4;
				tot++; l[tot] = ans - 5; mid[tot] = ans - 4; r[tot] = ans - 3;
			}
			else {
				if(ans <= (n - 6)) {	
					tot++; r[tot] = ans + 6; mid[tot] = ans + 3; l[tot] = ans;
					tot++; r[tot] = ans + 6; mid[tot] = ans + 5; l[tot] = ans + 4;
					tot++; r[tot] = ans + 5; mid[tot] = ans + 4; l[tot] = ans + 3;					
				}
				else {	
					tot++; l[tot] = ans - 3; mid[tot] = ans; r[tot] = ans + 3;
					tot++; l[tot] = ans - 3; mid[tot] = ans - 1; r[tot] = ans + 1;
					tot++; l[tot] = ans - 1; mid[tot] = ans + 1; r[tot] = ans + 3;
				}
			}
		}
	}
	printf("YES\n"); cout << tot << endl;
	for(register int i = 1; i <= tot; i++) printf("%d %d %d\n", l[i], mid[i], r[i]);
	return 0;
}