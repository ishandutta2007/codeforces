#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i <= b; i++)
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

const int N = 110;

char c[N];
int n;

int check(char c) {
	if(c >= 'a' && c <= 'z') return 0;
	if(c >= 'A' && c <= 'Z') return 1;
	return 2;
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		scanf("%s", c + 1);
		int len = strlen(c + 1);
		int s[3] = {0, 0, 0}, S[3] = {0, 0, 0};
		for(int j = 1; j <= len; j++) {
			s[check(c[j])] += 1;
			S[check(c[j])] = 1;
		}
		if(S[0] + S[1] + S[2] == 3) {
			for(int j = 1; j <= len; j++) printf("%c", c[j]);
		}
		if(S[0] + S[1] + S[2] == 2) {
			bool ok = 0;
			for(int j = 1; j <= len; j++) {
				if(s[check(c[j])] >= 2 && !ok) {
					if(s[0] == 0) printf("a");
					if(s[1] == 0) printf("A");
					if(s[2] == 0) printf("0");
					ok = 1;
				} else printf("%c", c[j]);
			}
		}
		if(S[0] + S[1] + S[2] == 1) {
			if(s[0]) c[1] = 'A', c[2] = '0';
			if(s[1]) c[1] = 'a', c[2] = '0';
			if(s[2]) c[1] = 'a', c[2] = 'A';
			for(int j = 1; j <= len; j++) printf("%c", c[j]);
		}
		printf("\n");
	}
	return 0;
}