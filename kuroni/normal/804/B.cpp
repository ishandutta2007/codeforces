#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int mod = 1000000007;
int i, cnt_b = 0, ans = 0;
char s[1000005];

int main()
{
    scanf("%s", s);
    for (i = strlen(s) - 1; i >= 0; i--)
    {
        if (s[i] == 'b')
            cnt_b++;
        else
        {
            ans = (ans + cnt_b) % mod;
            cnt_b = (cnt_b * 2) % mod;
        }
    }
    printf("%d", ans);
}