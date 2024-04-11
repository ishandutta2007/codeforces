#include <cstdio>
#include <map>
using namespace std;

map <int, int> A, B;

int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		A[a]++;
	}
	for (int i = 0; i < n - 1; i++) {
		int a; scanf("%d", &a);
		if (--A[a] == 0) A.erase(a);
		B[a]++;
	}
	printf("%d\n", A.begin()->first);
	for (int i = 0; i < n - 2; i++) {
		int a; scanf("%d", &a);
		if (--B[a] == 0) B.erase(a);
	}
	printf("%d\n", B.begin()->first);
	return 0;
}