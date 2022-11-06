#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", max(0, (n - 1) / 2));
    return 0;
}