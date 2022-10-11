#include <iostream>
#include <cstdio>
using namespace std;

int n;
char s[105];
bool chk;

int main()
{
    scanf("%d\n%s", &n, s + 1);
    for (int i = 1; i <= n; i++)
        if (s[i] == '1')
            chk = true;
    if (chk)
        printf("1");
    for (int i = 1; i <= n; i++)
        if (s[i] == '0')
            printf("0");
}