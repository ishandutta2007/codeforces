#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 1005;

int n;
int x[Maxn], y[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &x[i], &y[i]);
    for (int i = 0; i < n; i++) {
        int ni = (i + 1) % n;
        int ax = x[ni] - x[i], ay = y[ni] - y[i];
        int bx = x[(ni + 1) % n] - x[ni], by = y[(ni + 1) % n] - y[ni];
        if (ax * by - ay * bx > 0) res++;
    }
    printf("%d\n", res);
	return 0;
}