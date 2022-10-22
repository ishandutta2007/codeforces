#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    scanf("%d", &n);
    int pw = 0;
    while ((1 << pw) <= n) pw++;
    printf("%d\n", pw);
    return 0;
}