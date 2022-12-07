#include <bits/stdc++.h>
using namespace std;



int main() 
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        int a, b, n;
        scanf("%d %d %d", &n, &a, &b);
        if (a == n && b == n) puts("Yes");
        else if (a + b < n - 1) puts("Yes");
        else puts("No");
    }

    return 0;
}