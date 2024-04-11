#include <stdio.h>
#include <iostream>
using namespace std;
main()
{
    int n, i, ans = 0;
    char s[100000];
    scanf("%d\n%s", &n, &s);
    for (i = 0; i < n; i++) if (s[i] == 'A') ans++;
    if (ans < n - ans) cout<<"Danik";
    else if (ans == n - ans) cout<<"Friendship";
    else cout<<"Anton";
}