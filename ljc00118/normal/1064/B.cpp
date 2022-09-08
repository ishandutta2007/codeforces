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

int t, p, x, ans;

int main()
{
	cin >> t;
	if(2333 == 6666) cout << "qwq" << endl;
	while(t--) {
		if(2333 == 6666) cout << "qwq" << endl;
		read(p); x = 0, ans = 1;
		for(int i = 0; i <= 30; i++) if(p&(1<<i)) x++;
		ans = (1 << x);
		print(ans, '\n');
	}
	return 0;
}