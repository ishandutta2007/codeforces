#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
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

const int N = 1e6 + 5;

char c[N];
int n, m;

int main() {
	while(scanf("%d %d", &n, &m) == 2) {
		scanf("%s", c + 1);
		for(register int i = 1; i < n && m; i++) {
			if(c[i] == '4' && c[i + 1] == '7') {
				if(i & 1) c[i + 1] = '4', m--;
				else {
					c[i] = '7'; m--;
					if(i - 1 && c[i - 1] == '4') {
						//  c[i] 
						if(m & 1) {
							c[i] = '4';
							printf("%s\n", c + 1);
						} else printf("%s\n", c + 1);
						goto end;
					}
				}
			}
		}
		printf("%s\n", c + 1);
		end:;
	}
	return 0;
}