#include <cstdio>
using namespace std;

const int Maxn = 16;
//                    x  x  x  x  x     x  x  x  x  x     x     x
const int ar[Maxn] = {1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0};
//const int ar[Maxn] = {8848, 958, 12766, 6695, 1100, 807, 31962, 146, -68, 25, 134, 10000, 663268, 154103, 1642, 106};

int ind;

int main()
{
	scanf("%d", &ind);
	printf("%d\n", ar[ind - 1]);
	return 0;
}