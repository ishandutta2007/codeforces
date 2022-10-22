#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 200005;

int n, k;
char str[Maxn];
char res[Maxn];
int slen;

bool Less()
{
    for (int i = 0; i < slen; i++)
        if (str[i] != str[i % k])
            return str[i % k] < str[i];
    return false;
}

int main()
{
    scanf("%d %d", &n, &k);
    scanf("%s", str);
    slen = strlen(str);
    if (Less()) {
        int i = k - 1;
        while (i >= 0 && str[i] == '9') { str[i] = '0'; i--; }
        str[i]++;
    }
    for (int i = k; i < slen; i++)
        str[i] = str[i - k];
    printf("%d\n", n);
    printf("%s\n", str);
    return 0;
}