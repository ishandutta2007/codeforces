#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int per[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, ans = 1E9, cnt[6][10], n, cur, pw;
char s[10];
bool chk[10];

int main()
{
    scanf("%d\n", &n);
    while (n--)
    {
        scanf("%s\n", s + 1);
        chk[s[1] - 'a'] = true;
        for (int i = strlen(s + 1), pw = 0; i >= 1; pw++, i--)
            cnt[pw][s[i] - 'a']++;
    }
    do
        if (!chk[per[0]])
        {
            pw = 1;
            cur = 0;
            for (int i = 0; i < 6; pw *= 10, i++)
                for (int j = 0; j < 10; j++)
                    cur += pw * j * cnt[i][per[j]];
            ans = min(ans, cur);
        }
    while (next_permutation(per, per + 10));
    printf("%d", ans);
}