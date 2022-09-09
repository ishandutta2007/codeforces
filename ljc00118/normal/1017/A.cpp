#include <bits/stdc++.h>
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

const int N = 1000 + 10;
int a[N]; int n;

bool cmp(int a, int b) {return a > b;}

int main() {
	read(n);
	int A, B, C, D;
	read(A); read(B); read(C); read(D);
	int tmp = A + B + C + D; a[1] = tmp;
	for(int i = 2; i <= n; i++) {
		read(A); read(B); read(C); read(D);
		a[i] = A + B + C + D;
	}
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++) {
		if(a[i] == tmp) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}