#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, a, b;

int main() {

    scanf("%d %d %d", &n, &a, &b);
    a--;
    a += b;
    a %= n;
    a += n;
    a %= n;

    printf("%d\n", a + 1);

    return 0;
}