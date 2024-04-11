#include <bits/stdc++.h>
using namespace std;
main()
{
    char s[300000];
    int i;
    scanf("%s",&s);
    long long ans = (((int)s[0]) % 4 == 0);
    for (i = 1; i < strlen(s); i++) ans += ((int)s[i] % 4 == 0) + i*(((int)s[i] + (int)s[i-1] * 10) % 4 == 0);
    cout<<ans;
}