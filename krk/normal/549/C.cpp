#include <cstdio>
using namespace std;

const int Maxn = 200005;

int n, k;
int zers, ones, ch = 1;

bool winEq(int moves, int zers, int ones, int ch)
{
	if (moves == 0) return ch == 0;
	if (zers <= moves / 2)
		return (moves - zers) % 2 == ch;
	if (ones <= moves / 2)
		return ones % 2 == ch;
	return false;
}

bool winOdd(int moves, int zers, int ones, int ch)
{
	return zers && !winEq(moves - 1, zers - 1, ones, !ch) ||
	       ones && !winEq(moves - 1, zers, ones - 1, ch);
}

bool Win(int moves, int zers, int ones, int ch)
{
	return moves % 2? winOdd(moves, zers, ones, ch): winEq(moves, zers, ones, ch);
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		if (a % 2) { ones++; ch = !ch; }
		else zers++;
	}
	printf("%s\n", Win(n - k, zers, ones, ch)? "Stannis": "Daenerys");
	return 0;
}