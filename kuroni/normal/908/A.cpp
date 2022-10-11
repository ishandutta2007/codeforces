#include <iostream>
#include <cstdio>
using namespace std;

char s[55];
int ans = 0;

int main()
{
    scanf("%s", s + 1);
    for (int i = 1; s[i] != '\0'; i++)
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == '1' || s[i] == '3' || s[i] == '5' || s[i] == '7' || s[i] == '9')
            ++ans;
    printf("%d", ans);
}