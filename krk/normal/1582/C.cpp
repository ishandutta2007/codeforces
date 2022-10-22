#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int Inf = 1000000000;

int T;
int n;
char str[Maxn];

int Solve(char ch)
{
    int res = 0;
    int l = 0, r = n - 1;
    while (l < r)
        if (str[l] == str[r]) l++, r--;
        else if (str[l] == ch) { res++; l++; }
        else if (str[r] == ch) { res++; r--; }
        else return Inf;
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", str);
        int res = Inf;
        for (char ch = 'a'; ch <= 'z'; ch++)
            res = min(res, Solve(ch));
        printf("%d\n", res >= Inf? -1: res);
    }
    return 0;
}