#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int Maxn = 105;

int a, b;
int x[Maxn], y[Maxn];
int dx, dy;
string s;

int main()
{

	scanf("%d %d", &a, &b);
	cin >> s;
	x[0] = y[0] = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'U') dy++;
		else if (s[i] == 'D') dy--;
		else if (s[i] == 'L') dx--;
		else if (s[i] == 'R') dx++;
		x[i + 1] = dx; y[i + 1] = dy;
	}
	int i;
	for (i = 0; i <= s.length(); i++) 
		if (dx == 0 && dy == 0) { if (x[i] == a && y[i] == b) break; }
		else {
			int tims = dx? (a - x[i]) / dx: (b - y[i]) / dy;
			if (tims >= 0 && x[i] + tims * dx == a && y[i] + tims * dy == b) break;
		}
	printf("%s\n", i <= s.length()? "Yes": "No");
	return 0;
}