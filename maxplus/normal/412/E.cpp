#include <iostream>
#include <cstdlib>
#include <cstdio>

//#include <algorithm>
//#include <cstring>
//#include <string>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <cmath>


using namespace std;

char s[1000001];

long long n, part = 1, part1, part2, part3, end, ans;

int main()
{

    for (n = 0; cin >> s[n] > 0 && s[n] != '|'; ++n);

    for (int i = 0; i < n; ++i)
    {
        end = 0;
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            if (part == 1)
                part1++;
            else if (part == 3)
                part3++;
            else if (part == 2 && part2 == 0)
                part2 = 1;
        }

        if (s[i] >= '0' && s[i] <= '9')
            if (part == 3)
                end = 1;
            else if (part == 2 && part2 == 0)
                part2 = 1;

        if (s[i] == '_')
            if (part == 2)
                end = 2;
            else if (part == 3)
                end = 1;

        if (s[i] == '@')
            if (part == 1)
                part = 2;
            else if (part == 2)
                end = 2;
            else
                end = 1;

        if (s[i] == '.')
            if (part == 2 && part2 != 0)
                part = 3;
            else if (part == 3)
                end = 1;
            else
                end = 2;

        if (end == 0 && i == n - 1 && part == 3)
            end = 1;

        if (end == 1)
            ans += part1 * part3;

        if (end != 0)
        {
            part1 = part2 = part3 = 0;
            part = 1;
            if (s[i] != '.' && i != n - 1)
            {
                i--;
                while (((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '_') && i != 0)
                    i--;
            }
        }
    }
    cout << ans;
    return 0;
}