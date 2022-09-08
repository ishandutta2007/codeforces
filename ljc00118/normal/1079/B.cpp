#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define For(i, a, b) for(register int i = a; i <= b; i++)
#define Rof(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
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

const int N = 105;

char c[N];
int n;

int main() {
	scanf("%s", c + 1); n = strlen(c + 1); int now = 0;
	for(register int i = 1; i <= 5; i++) {
		if((n + i - 1) / i > 20) continue;
		int maxlen = (n + i - 1) / i;
		int qwq = (n - 1) % i + 1;
		cout << i << " " << maxlen << endl;
		for(register int j = 1; j <= qwq; j++) {
			for(register int j = 1; j <= maxlen; j++) {
				now++;
				putchar(c[now]);
			}
			putchar('\n');
		}
		for(register int j = qwq + 1; j <= i; j++) {
			putchar('*');
			for(register int j = 2; j <= maxlen; j++) {
				now++;
				putchar(c[now]);
			}
			putchar('\n');
		}
		break;
	}
	return 0;
}