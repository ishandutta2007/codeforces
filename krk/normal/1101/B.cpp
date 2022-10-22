#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
    cin >> s;
    int l1, l2;
    int r1, r2;
    l1 = 0;
    while (l1 < s.length() && s[l1] != '[') l1++;
    l2 = l1 + 1;
    while (l2 < s.length() && s[l2] != ':') l2++;
    r1 = int(s.length()) - 1;
    while (r1 >= 0 && s[r1] != ']') r1--;
    r2 = r1 - 1;
    while (r2 >= 0 && s[r2] != ':') r2--;
    if (l2 >= r2) { printf("-1\n"); return 0; }
    int res = 4;
    for (int i = l2 + 1; i <= r2 - 1; i++)
        if (s[i] == '|') res++;
    printf("%d\n", res);
    return 0;
}