#include <bits/stdc++.h>
using namespace std;

bool Check(int n)
{
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum % 4 == 0;
}

int main()
{
    int a; scanf("%d", &a);
    while (!Check(a)) a++;
    printf("%d\n", a);
    return 0;
}