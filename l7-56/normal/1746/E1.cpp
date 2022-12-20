#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector <int> vi;
typedef pair <int, int> pii;
#define fir first
#define sec second
template <typename __Tp> void read(__Tp &x) {
    int f = 0; x = 0; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
    for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    if (f) x = -x;
}
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &...y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
void write(const char *s) { for (int i = 0; s[i]; ++i) putchar(s[i]); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ...y) { write(x), write(y...); }

int ask(vi s) {
    write('?', ' ', s.size());
    for (int x : s) write(' ', x);
    write('\n');
    fflush(stdout);
    char str[10]; scanf("%s", str);
    return str[0] == 'Y';
}

int prt(int x) {
    write('!', ' ', x, '\n');
    fflush(stdout);
    char str[10]; scanf("%s", str);
    return str[1] == ')';
}

int main() {
    int n;
    read(n);
	vi vec;
	for (int i = 1; i <= n; ++i) vec.push_back(i);
	while (vec.size() > 2) {
		vi a[3];
		for (int i = 0; i < (int) vec.size(); ++i) a[i % 3].push_back(vec[i]);
		int res;
		if (ask(a[0])) {
			if (ask(a[1])) res = 2;
			else res = 1;
		}
		else {
			if (ask(a[0])) {
				if (ask(a[1])) res = 2;
				else res = 1;
			}
			else res = 0;
		}
		vec.clear();
		for (int i = 0; i < 3; ++i) if (i != res)
			for (int x : a[i]) vec.push_back(x);
	}
	for (int x : vec) if (prt(x)) return 0;
	return 0;
}