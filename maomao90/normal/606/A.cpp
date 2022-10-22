#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int x, y, z;

int main() {
	scanf("%d%d%d", &a, &b, &c);
	scanf("%d%d%d", &x, &y, &z);
	int da = x - a;
	int db = y - b;
	int dc = z - c;
	while (da > 0) {
		if (db < dc) db += 2;
		else dc += 2;
		da--;
	}
	while (db > 0) {
		if (da < dc) da += 2;
		else dc += 2;
		db--;
	}
	while (dc > 0) {
		if (da < db) da += 2;
		else db += 2;
		dc--;
	}
	if (da <= 0 && db <= 0 && dc <= 0) printf("YES\n");
	else printf("NO\n");
	return 0;
}