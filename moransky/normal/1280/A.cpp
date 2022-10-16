#include <iostream>
#include <cstdio>
#include <cstring>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef long long LL;

void inline read(int &x) {
    x = 0; char s = getchar();
    while (s < '0' || s > '9') s = getchar();
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
}

const int N = 1e6 + 5, P = 1e9 + 7;

int x, S;

char s[N];

int n;

void cp(int l, int r) {
	for (int i = l; i <= r; i++) {
		if (n >= x) break;
		s[++n] = s[i];
	}
}

int main() {
	int T; read(T);
	while (T--) {
		read(x); scanf("%s", s + 1);
		n = strlen(s + 1);
		S = n;
		bool o = 0;
		for (int i = 1; i <= x; i++) {
			int L = i + 1, R = S;
			S = (i + (LL)(S - i + P) * (s[i] - '0')) % P;
				
			for (int j = 0; j < s[i] - '0' - 1; j++) {
				cp(L, R);
			}
		}	
		printf("%d\n", S);
	}	
	return 0;
}