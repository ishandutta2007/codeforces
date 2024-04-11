#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int Maxd = 26;

int d;
int f[Maxd];
int n;
string res;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{
	scanf("%d", &d);
	int odd = 0;
	for (int i = 0; i < d; i++) {
		scanf("%d", &f[i]);
		n += f[i];
		odd += f[i] % 2;
	}
	for (int i = 0; i < d; i++)
		if (f[i] == n) { 
			printf("%d\n", n); 
			printf("%s\n", string(n, 'a' + i).c_str());
			return 0; 
		}
	if (odd > 1) { 
		printf("0\n");
		for (int i = 0; i < d; i++)
			printf("%s", string(f[i], 'a' + i).c_str()); 
		printf("\n");
		return 0; 
	}
	if (odd == 1) {
		int g = 0;
		for (int i = 0; i < d; i++)
			g = gcd(g, f[i]);
		string my;
		my.resize(n / g);
		int beg = 0, en = my.size() - 1;
		for (int i = 0; i < d; i++)
			if (f[i] % 2) {
				my[beg++] = 'a' + i;
				f[i] -= g;
			}
		for (int i = 0; i < d; i++)
			while (f[i] >= 2 * g) {
				my[beg++] = my[en--] = 'a' + i;
				f[i] -= 2 * g;
			}
		printf("%d\n", g);
		for (int i = 0; i < g; i++)
			printf("%s", my.c_str());
		printf("\n");
	} else {
		int g = 0;
		for (int i = 0; i < d; i++)
			g = gcd(g, f[i]);
		string my;
		for (int i = 0; i < d; i++)
			my += string(f[i] / g, 'a' + i);
		printf("%d\n", g);
		for (int i = 0; i < g; i++) {
			printf("%s", my.c_str());
			reverse(my.begin(), my.end());
		}
		printf("\n");
	}
	return 0;
}