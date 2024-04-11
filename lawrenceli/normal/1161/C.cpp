#include <bits/stdc++.h>

using namespace std;

int n, a[55];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    if (a[n/2] == a[0]) printf("Bob\n");
    else printf("Alice\n");
}