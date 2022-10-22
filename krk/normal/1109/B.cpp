#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 5005;

char s[Maxn];
int slen;
int res = 10;

bool Palin(int l, int r)
{
    while (l < r)
        if (s[l] != s[r]) return false;
        else l++, r--;
    return true;
}

int main()
{
    scanf("%s", s + 1);
    slen = strlen(s + 1);
    for (int i = 1; 2 * i <= slen; i++)
        if (!Palin(1, i))
            if (2 * i == slen || Palin(1, 2 * i) && Palin(2 * i + 1, slen)) res = min(res, 1);
            else res = min(res, 2);
    if (res >= 10) printf("Impossible\n");
    else printf("%d\n", res);
    return 0;
}