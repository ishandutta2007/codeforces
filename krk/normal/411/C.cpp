#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxd = 4;

int a[Maxd], b[Maxd];

bool Win(int def1, int atk1, int def2, int atk2)
{
	return def1 > atk2 && atk1 > def2;
}

int getSt(int def1, int atk1, int def2, int atk2)
{
	if (Win(def1, atk1, def2, atk2)) return 1;
	if (Win(def2, atk2, def1, atk1)) return -1;
	return 0;
}

int Get(int def, int atk)
{
	return min(getSt(def, atk, a[2], b[3]), getSt(def, atk, a[3], b[2]));
}

int main()
{
	for (int i = 0; i < Maxd; i++)
		scanf("%d %d", &a[i], &b[i]);
	int res = max(Get(a[0], b[1]), Get(a[1], b[0]));
	if (res > 0) printf("Team 1\n");
	else if (res == 0) printf("Draw\n");
	else printf("Team 2\n");
	return 0;
}