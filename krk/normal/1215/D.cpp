#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
char str[Maxn];
int s1, p1;
int s2, p2;

int main()
{
    scanf("%d", &n);
    scanf("%s", str);
    for (int i = 0; i < n / 2; i++)
        if (str[i] == '?') p1++;
        else s1 += int(str[i] - '0');
    for (int i = n / 2; i < n; i++)
        if (str[i] == '?') p2++;
        else s2 += int(str[i] - '0');
    if (s1 < s2) { swap(s1, s2); swap(p1, p2); }
    int res1 = s1 - s2 - 9 * p2 + 9 * (p1 + p2) / 2;
    int res2 = s2 - s1 - 9 * p1 + 9 * (p1 + p2) / 2;
    if (res1 > 0 || res2 > 0) printf("Monocarp\n");
    else printf("Bicarp\n");
    return 0;
}