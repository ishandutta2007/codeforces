#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 210;

int n, a[MAXN], cnt, minn = 1e9, sum;
bool good;

int main() {
    scanf("%d", &n);
    for (int i=0; i<2*n-1; i++) {
        scanf("%d", &a[i]);
        if (a[i] < 0) cnt++;
        if (a[i] == 0) good = 1;
        minn = min(minn, abs(a[i]));
        sum += abs(a[i]);
    }
    if (n%2==1 || good || cnt%2 == 0) {
        printf("%d\n", sum);
        return 0;
    }
    printf("%d\n", sum - 2*minn);
}