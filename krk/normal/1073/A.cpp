#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main()
{
    cin >> n;
    cin >> s;
    for (int i = 0; i + 1 < n; i++)
        if (s[i] != s[i + 1]) {
            printf("YES\n");
            printf("%c%c\n", s[i], s[i + 1]);
            return 0;
        }
    printf("NO\n");
    return 0;
}