#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int sett[5005][5005], cnt[5005], i, j;
bool palin[5005][5005];
string s;

int main()
{
    cin >> s;
    memset(palin, 1, sizeof(palin));
    memset(sett, 0, sizeof(sett));
    for (i = 1; i <= s.size(); i++)
        for (j = 0; j < s.size() - i + 1; j++)
        {
            if (i == 1)
                palin[j][j + i - 1] = true;
            else palin[j][j + i - 1] = ((palin[j + 1][j + i - 2]) && (s[j] == s[j + i - 1]));
        }
    for (i = 1; i <= s.size(); i++)
        for (j = 0; j < s.size() - i + 1; j++)
        {
            if (palin[j][j + i - 1])
            {
                sett[j][j + i - 1] = sett[j][j + i / 2 - 1] + 1;
                cnt[sett[j][j + i - 1]]++;
            }
        }
    for (i = s.size() - 1; i >= 1; i--)
        cnt[i] += cnt[i + 1];
    for (i = 1; i <= s.size(); i++)
        printf("%d ", cnt[i]);
}