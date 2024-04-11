#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
char str[Maxn];
char ch[Maxn];

int Solve(char a, char b, bool pr = false)
{
    for (int i = 0; i < n; i++) {
        if (str[i] == '?') { ch[i] = a; swap(a, b); }
        else {
            ch[i] = str[i];
            if (a == ch[i]) swap(a, b);
        }
    }
    if (pr) {
        ch[n] = '\0';
        printf("%s\n", ch);
    }
    int res = 0;
    for (int i = 0; i + 1 < n; i++)
        res += ch[i] == ch[i + 1];
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", str);
        int res1 = Solve('B', 'R'), res2 = Solve('R', 'B');
        if (res1 <= res2) Solve('B', 'R', true);
        else Solve('R', 'B', true);
    }
    return 0;
}