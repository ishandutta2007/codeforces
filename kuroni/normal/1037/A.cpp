#include <iostream>
#include <cstdio>
using namespace std;

int n;

int main()
{
    scanf("%d", &n);
    printf("%d", 32 - __builtin_clz(n));
}