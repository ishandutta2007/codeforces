#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

int main()
{
    scanf("%d", &n);
    int mn = 52, cnt = 0;
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        if (a < mn) { mn = a; cnt = 0; }
        if (a == mn) cnt++;
    }
    printf("%s\n", cnt <= n / 2? "Alice": "Bob");
    return 0;
}