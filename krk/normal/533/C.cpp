#include <cstdio>
#include <algorithm>
using namespace std;

int x1, y1, x2, y2;

void First() { printf("Polycarp\n"); }

void Second() { printf("Vasiliy\n"); }

int main()
{
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	if (x1 + y1 <= max(x2, y2)) First();
	else if (x2 + y2 < x1 + y1) Second();
	else {
		bool found = false;
		for (int i = 1; (i <= x2 || i <= y2) && !found; i++) {
			int nx = max(x2 - i, 0), ny = max(y2 - i, 0);
			found = x1 >= nx && y1 >= ny && x1 - nx + y1 - ny <= i;
		}
		if (found) First();
		else Second();
	}
	return 0;
}