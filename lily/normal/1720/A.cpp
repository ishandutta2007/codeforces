#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define read(a) scanf("%d", &a)


int main() {
	int T;
	read(T);
	while (T--) {
		int a, b, c, d;
		read(a); read(b); read(c); read(d);
		LL A = (LL) c * b / d;
		LL C = (LL) a * d / b;
		if ((LL)a * d == (LL)b * c) puts ("0");
		else if (!a || !c) puts ("1");
		else if (A % a == 0 && A * d == (LL) b * c) puts ("1");
		else if (C % c == 0 && C * b == (LL) a * d) puts ("1");
		else {
			assert (a); assert (c);
			LL B = (LL)a * d / c;
			LL D = (LL)b * c / a;
			if (B && B % b == 0 && (LL) a * d == B * c) puts("1");
			else if (D && D % d == 0 && (LL) a * D == b * c) puts ("1");
			else puts ("2");
		}
	}
}