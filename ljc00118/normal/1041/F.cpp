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

const int N = 1e6 + 5;

map <int, int> fst;
map <int, int> ff1, ff2;
map <int, int> :: iterator it;
int a[N], b[N], y32768, y32769, ans;
int n1, n2;

int main() {	
	read(n1); read(y32768); 
	For(i, 1, n1) read(a[i]), fst[a[i]] = 1;
	read(n2); read(y32769); 
	For(i, 1, n2) {
		read(b[i]);
		if(fst[b[i]]) ans = 2;
	}
	for(int len = 2; ; len <<= 1) {
		ff1.clear();
		ff2.clear();
		For(i, 1, n1) ff1[a[i] % len] += 1;
		For(i, 1, n2) ff2[b[i] % len] += 1;
		for(it = ff1.begin(); it != ff1.end(); it++) ans = max(ans, it -> second + ff2[(it -> first + (len / 2)) % len]);
		for(it = ff2.begin(); it != ff2.end(); it++) ans = max(ans, it -> second + ff1[(it -> first + (len / 2)) % len]);
		if(len == (1 << 31)) break;
	}
	cout << ans << endl;
	return 0;
}