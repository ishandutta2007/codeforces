#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

int main(){
    scanf("%d%d", &n, &m);
    if (n == 1 && m == 1)
    {
        printf("%.10f\n", 1.0);
        return 0;
    }
    double ans = 1.00 * (m - 1) * (n - 1) / (n * m - 1) / n + 1.00  / n;
    printf("%.10f\n", ans);
}