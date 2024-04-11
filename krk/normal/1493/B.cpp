#include <bits/stdc++.h>
using namespace std;

int T;
int h, m;

bool Oth(int &num)
{
	if (num == 0 || num == 1 || num == 8) return true;
	if (num == 2) { num = 5; return true; }
	if (num == 5) { num = 2; return true; }
	return false;
}

bool Valid(int a, int b)
{
	int fir = b % 10, sec = b / 10, thir = a % 10, four = a / 10;
	if (!Oth(fir) || !Oth(sec) || !Oth(thir) || !Oth(four)) return false;
	a = 10 * fir + sec;
	b = 10 * thir + four;
	return a < h && b < m;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &h, &m);
		string s;
		cin >> s;
		int a = 10 * int(s[0] - '0') + int(s[1] - '0');
		int b = 10 * int(s[3] - '0') + int(s[4] - '0');
		while (!Valid(a, b)) {
			b++;
			if (b >= m) { a++; b = 0; }
			if (a >= h) a = 0;
		}
		printf("%d%d:%d%d\n", a / 10, a % 10, b / 10, b % 10);
	}
    return 0;
}