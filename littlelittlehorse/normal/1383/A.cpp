#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, test, f[26];
char str1[100011], str2[100011];
bool b[26][26];

int gf(int i) {
    if (i == f[i])
        return i;
    return f[i] = gf(f[i]);
}

int main() {
    scanf("%d", &test);
    for (; test--; ) {
        scanf("%d", &n);
        scanf("%s%s", str1 + 1, str2 + 1);
        memset(b, false, sizeof(b));
        for (int i = 0; i < 26; i++)
            f[i] = i;
        for (int i = 1; i <= n; i++)
            b[str1[i] - 'a'][str2[i] - 'a'] = true,
            f[gf(str1[i] - 'a')] = gf(str2[i] - 'a');
        bool ok = true;
        int cnt = 0;
        for (int i = 0; i < 26 && ok; i++)
            for (int j = 0; j < 26 && ok; j++)
                if (b[i][j])
                    if (j < i)
                        ok = false;
        cnt = 26;
        for (int i = 0; i < 26; i++)
            if (gf(i) == i)
                --cnt;
        if (!ok)
            printf("-1\n");
        else
            printf("%d\n", cnt);
    }
}