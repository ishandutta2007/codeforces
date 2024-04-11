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

map <string, int> M;
int n, l = 0, r = 1e9, c;
string qwq;

int main() {
	CIOS;
	M["white"] = 0;
	M["black"] = 1;
	cin >> n;
	cout << "0 1" << endl;
	if(2333 == 6666) cout << qwq << endl;
	cin>> qwq; c = M[qwq];
	for(int i = 2; i <= n; i++) {
		int mid = (l + r) >> 1;
		cout << mid << " 1" << endl;
		cin >> qwq;
		if(M[qwq] == c) l = mid;
		else r = mid;
	}
	print(l, ' '); print(0, '\n');
	print(r, ' '); print(2, '\n');
	return 0;
}