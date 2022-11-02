#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int f[27], n, v[101][101];
char str[101], str1[101], str2[101];

int main(){
    memset(f, 0, sizeof(f));
    scanf("%s", str); n = strlen(str);
    memcpy(str1, str, sizeof(str1));
    for (int i = 0; i < n; i++) ++f[str[i] - 'a'];
    scanf("%s", str); n = strlen(str);
    memcpy(str2, str, sizeof(str2));
    for (int i = 0; i < n; i++) --f[str[i] - 'a'];
    bool ok = true;
    for (int i = 0; i < 26 && ok; i++)
        if (f[i] < 0) ok = false;
    if (!ok)
    {
        puts("need tree");
        return 0;
    }
    ok = true;
    for (int i = 0; i < 26 && ok; i++)
        if (f[i]) ok = false;
    if (ok) puts("array");
    else
    {
        int len1 = strlen(str1), len2 = strlen(str2);
        memset(v, 0, sizeof(v));
        for (int i = 1; i <= len1; i++)
            for (int j = 1; j <= len2; j++)
            {
                v[i][j] = max(v[i - 1][j], v[i][j - 1]);
                if (str1[i - 1] == str2[j - 1])
                    v[i][j] = max(v[i][j], v[i - 1][j - 1] + 1);
            }
        if (v[len1][len2] == len2) puts("automaton");
        else puts("both");
    }
}