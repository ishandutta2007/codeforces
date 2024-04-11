#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#include <iomanip>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    if (n <= 5) printf("-1\n");
    else {
        printf("1 3\n");
        printf("2 3\n");
        printf("3 4\n");
        for (int i = 5; i <= n; i++)
            printf("4 %d\n", i);
    }
    for (int i = 2; i <= n; i++)
        printf("%d %d\n", i - 1, i);
	return 0;
}