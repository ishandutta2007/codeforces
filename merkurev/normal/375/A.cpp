#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int a[4] = {1, 6, 8, 9};
char s[1500500];
int cnt[10];
char ans[1500500];
int anslen = 0;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len; i++)
        cnt[s[i] - '0']++;
    cnt[1]--;
    cnt[6]--;
    cnt[8]--;
    cnt[9]--;
    if (cnt[0] != len - 4)
    {
        int rem = 0;
        for (int i = 9; i >= 0; i--)
        {
            while (cnt[i] )
            {
                cnt[i]--;
                rem = (rem * 10 + i) % 7;
                ans[anslen++] = '0' + i;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            rem *= 10;
            rem %= 7;
        }

        do
        {
            int x = 0;
            for (int i = 0; i < 4; i++)
            {
                x = (x * 10 + a[i] ) % 7;
            }
            if ( (x + rem) % 7 == 0)
            {
                for (int i = 0; i < 4; i++)
                    ans[anslen++] = '0' + a[i];
                printf("%s", ans);
                return 0;
            }
        } while (next_permutation(a, a + 4) );

    }
    anslen = 4;
    while (cnt[0] )
    {
        cnt[0]--;
        ans[anslen++] = '0';
    }

    do
    {
        int x = 0;
        for (int i = 0; i < 4; i++)
        {
            x = (x * 10 + a[i] ) % 7;
        }
        if (x == 0)
        {
            for (int i = 0; i < 4; i++)
                ans[i] = '0' + a[i];
            printf("%s", ans);
            return 0;
        }
    } while (next_permutation(a, a + 4) );


    



    return 0;
}