#include <vector>
#include <cstdio>
using namespace std;

int x, y, a, b;
vector <int> r1, r2;

int main()
{
	scanf("%d %d %d %d", &x, &y, &a, &b);
	for (int i = a; i <= x; i++)
		for (int j = b; j <= y && j < i; j++) {
			r1.push_back(i); r2.push_back(j);
		}
	printf("%d\n", r1.size());
	for (int i = 0; i < r1.size(); i++)
		printf("%d %d\n", r1[i], r2[i]);
	return 0;
}