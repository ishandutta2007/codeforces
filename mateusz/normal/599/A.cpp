#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int main() {

    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    a = min(a, b + c);
    b = min(b, a + c);
    c = min(c, a + b);

    printf("%d\n", a + c + b);

    return 0;
}