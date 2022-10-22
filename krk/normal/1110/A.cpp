#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int b, k;
int a[Maxn];

int main()
{
    scanf("%d %d", &b, &k);
    for (int i = 0; i < k; i++)
        scanf("%d", &a[i]);
    bool even;
    if (b % 2 == 0)
        even = a[k - 1] % 2 == 0;
    else {
        int sum = 0;
        for (int i = 0; i < k; i++)
            sum += a[i];
        even = sum % 2 == 0;
    }
    printf("%s\n", even? "even": "odd");
    return 0;
}