// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 5005;

int n;

char s[N];

int L[3], R[3], c[3];

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++) {
		int ch = s[i] - 'a';
		if (!L[ch]) L[ch] = i;
		R[ch] = i;
		c[ch]++;
	} 
	for (int i = 0; i < 2; i++)
		if (R[i] >= L[i + 1]) {
			puts("NO");
			return 0;
		}
	if (!c[0] || !c[1]) {
		puts("NO");
		return 0;
	}
	if (!(c[2] == c[1] || c[2] == c[0])) {
		puts("NO");
		return 0;
	}
	puts("YES");
	
    return 0;
}