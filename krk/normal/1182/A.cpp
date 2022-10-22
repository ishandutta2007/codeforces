#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    cin >> n;
    if (n % 2) printf("0\n");
    else {
        int res = 1;
        for (int i = 0; i < n / 2; i++)
            res *= 2;
        printf("%d\n", res);
    }
    return 0;
}