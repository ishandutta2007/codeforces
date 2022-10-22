#include <cstdio>
#include <set>
using namespace std;

int y;

bool Distinct(int y)
{
	set <int> S;
	for (int i = 0; i < 4; i++) {
		S.insert(y % 10); y /= 10;
	}
	return S.size() == 4;
}

int main()
{
	scanf("%d", &y);
	for (y++; ; y++)
		if (Distinct(y)) break;
	printf("%d\n", y);
	return 0;
}