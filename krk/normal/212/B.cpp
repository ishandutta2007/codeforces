#include <cstdio>
#include <cstring>
using namespace std;

const int Maxn = 1000005;

char s[Maxn];
int n;
int m;
char x[Maxn];
int len;
int quer[Maxn];
short inplace[1 << 26];
int place[Maxn];

int main()
{
    scanf("%s", s); n = strlen(s);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%s", x); len = strlen(x);
        int mask = 0;
        for (int j = 0; j < len; j++)
            mask |= 1 << x[j] - 'a';
        inplace[mask] = i; quer[i] = mask;
    }
    for (int i = 0; i < n; i++) {
        int mask = 0;
        for (int j = i; j < n; j++) {
            if (i < j && s[i] == s[j]) break;
            mask |= 1 << s[j] - 'a';
            if (j + 1 == n || !(mask & 1 << s[j + 1] - 'a')) place[inplace[mask]]++;
        }
    }
    for (int i = 1; i <= m; i++)
        printf("%d\n", place[inplace[quer[i]]]);
    return 0;
}