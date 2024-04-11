#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

char tmp[Maxn];
int T;
int n;
char c;

string Read()
{
    scanf("%s", tmp);
    return tmp;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %c", &n, &c);
        string str = Read();
        str = str + str;
        int res = 0;
        int lst;
        for (int i = 2 * n - 1; i >= n; i--)
            if (str[i] == 'g') lst = i;
        for (int i = n - 1; i >= 0; i--) {
            if (str[i] == 'g') lst = i;
            if (str[i] == c) res = max(res, lst - i);
        }
        printf("%d\n", res);
    }
    return 0;
}