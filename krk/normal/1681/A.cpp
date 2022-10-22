#include <bits/stdc++.h>
using namespace std;

int T;

int readMax()
{
    int n; scanf("%d", &n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        mx = max(mx, a);
    }
    return mx;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        int A = readMax(), B = readMax();
        printf("%s\n", A >= B? "Alice": "Bob");
        printf("%s\n", B >= A? "Bob": "Alice");
    }
    return 0;
}