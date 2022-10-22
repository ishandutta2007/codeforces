#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, q;
int one, two;
bool rev;

int main()
{
	scanf("%d %d", &n, &q);
	int hlf = n / 2;
	for (int i = 0; i < q; i++) {
		int typ, x;
		scanf("%d", &typ);
		if (typ == 1) {
			scanf("%d", &x);
			if (x >= 0) {
				int lst = (x + 1) / 2;
				int blst = x / 2;
				if (rev) {
					one = (one - lst % hlf + hlf) % hlf;
					two = (two - blst % hlf + hlf) % hlf; 
				} else {
					one = (one - blst % hlf + hlf) % hlf;
					two = (two - lst % hlf + hlf) % hlf;
				}
				if (x % 2 != 0) rev = !rev;
			} else {
				x = -x;
				int lst = (x + 1) / 2;
				int blst = x / 2;
				if (rev) {
					two = (two + lst) % hlf;
					one = (one + blst) % hlf;
				} else {
					two = (two + blst) % hlf;
					one = (one + lst) % hlf;
				}
				if (x % 2 != 0) rev = !rev;
			}
		} else rev = !rev;
	}
	for (int i = 0; i < n; i++) {
		if (rev) { printf("%d", 2 * (two + 1)); two = (two + 1) % hlf; }
		else { printf("%d", 2 * one + 1); one = (one + 1) % hlf; }
		rev = !rev;
		printf("%c", i + 1 < n? ' ': '\n');
	}
	return 0;
}