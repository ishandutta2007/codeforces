#include <bits/stdc++.h>

using namespace std;

int ans = 999999999, kol = 1, n, m, last_light, l[16], r[16];
char a[20][200];

string get(int a)
{
    string res = "";
    int i = 1;
    while (i*2 <= a)
        i *= 2;
    while (i != 0)
    {
        res = res + char(a/i+48);
        a %= i;
        i /= 2;
    }
    while (res.size() < last_light)
        res = '0' + res;
    res = '#'+res;
    return res;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m + 2; j++)
        {
            cin >> a[n-i+1][j];
            if (a[n-i+1][j] == '1')
            {
                if (l[n-i+1] == 0)
                    l[n-i+1] = j;
                r[n-i+1] = j;
                last_light = max(n-i+1, last_light);
            }
        }
    for (int i = 0; i < last_light; i++)
        kol *= 2;
    string s;
    int cur = 0, cpos;
    for (int y = 0; y < kol; y++)
    {
        cur = 0;
        s = get(y);
        s[1] = '0';
        for (int i = 1; i <= last_light; i++)
        {
            if (i != 1)
                cur++;
            if (r[i] != 0) {
            if (s[i] == '0')
            {
                cur += r[i]-1;
                cpos = r[i];
            }
            if (s[i] == '1')
            {
                cur += m+2 - l[i];
                cpos = l[i];
            }

            if (i != last_light)
            {

                if(s[i+1] == '0')
                    cur += cpos - 1;
                else
                    cur += m+2 - cpos;
            }
            }else {

             if (i != last_light && s[i] != s[i+1])
                    cur += m+1;
            }

        }
        ans = min(ans, cur);
    }
    cout << ans;
    return 0;
}