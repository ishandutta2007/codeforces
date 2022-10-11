#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

int n, t, ret = 0, cnt = 26;
bool chk[26], sv[26];
char c, s[100005];

int main()
{
    scanf("%d\n", &n);
    while (--n)
    {
        scanf("%c %s\n", &c, s + 1);
        if (cnt == 1)
            ret += (c != '.');
        else
        {
            t = strlen(s + 1);
            if (c == '!')
            {
                fill(sv, sv + 26, false);
                for (int i = 1; i <= t; i++)
                    sv[s[i] - 'a'] = true;
                for (int i = 0; i < 26; i++)
                    if (!sv[i] && !chk[i])
                    {
                        chk[i] = true;
                        cnt--;
                    }
            }
            else
                for (int i = 1; i <= t; i++)
                    if (!chk[s[i] - 'a'])
                    {
                        chk[s[i] - 'a'] = true;
                        cnt--;
                    }
        }
    }
    printf("%d", ret);
}