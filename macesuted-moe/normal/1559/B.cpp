#include <bits/stdc++.h>

int main()
{
    int n;
    std::cin >> n;
    while (n--)
    {
        int n, flg = 0;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        for (int i = 0; i < n; ++i)
            if (s[i] != '?')
                flg = 1;
        if (flg == 0)
        {
            for (int i = 0; i < n; ++i)
                s[i] = i & 1 ? 'B' : 'R';
        }
        else
            for (int i = 1; i < n; ++i)
                if (s[i] != '?')
                    for (int j = i - 1; s[j] == '?'; --j)
                        s[j] = s[j + 1] == 'B' ? 'R' : 'B';
        for (int i = n - 1; i >= 0; --i)
            if (s[i] == '?' && s[i - 1] != '?')
            {
                for (int j = i; j < n; ++j)
                    s[j] = s[j - 1] == 'B' ? 'R' : 'B';
                break;
            }
        std::cout << s << std::endl;
    }
    return 0;
}