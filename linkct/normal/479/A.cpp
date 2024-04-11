#include <cstdio>
#include <algorithm>
using std :: sort;

int main(){
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int arr[10] = {
		(a + b) * c, a + b + c,
		a * b + c, a * b * c,
		a + b * c, a * (b + c)
	};
	sort(arr, arr + 6);
	printf("%d\n", arr[5]);
	return 0;
}