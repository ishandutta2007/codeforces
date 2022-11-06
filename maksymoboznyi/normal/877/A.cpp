#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;


int is[6];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, ss = "";

    cin >> s;
      for (int l = 0; l+4 < s.size(); l++)
    {
        if (s[l] == 'd' && s[l+1] == 'A' && s[l+2] == 'N' && s[l+3] == 'I' && s[l+4] == 'L')
            is[1] += 1;
    }
    for (int l = 0; l + 3 < s.size(); l++)
    {
        if (s[l] == 'o' && s[l+1] == 'L' && s[l+2] == 'Y' && s[l+3] == 'A')
            is[2] += 1;
    }
    for (int l = 0; l + 4 <  s.size(); l++)
        if (s[l] == 's' && s[l+1] == 'L' && s[l+2] == 'A' && s[l+3] == 'V' && s[l+4] == 'A')
            is[3] += 1;
    for (int l = 0; l + 2 < s.size(); l++)
        if (s[l] == 'a' && s[l+1] == 'N' && s[l+2] == 'N')
            is[4] += 1;
    for (int l = 0; l + 5 < s.size(); l++)
        if (s[l] == 'n' && s[l+1] == 'I' && s[l+2] == 'K' && s[l+3] == 'I' && s[l+4] == 'T' && s[l+5] == 'A')
            is[5] += 1;



    for (int l = 0; l+4 < s.size(); l++)
    {
        if (s[l] == 'D' && s[l+1] == 'a' && s[l+2] == 'n' && s[l+3] == 'i' && s[l+4] == 'l')
            is[1] += 1;
    }
    for (int l = 0; l + 3 < s.size(); l++)
    {
        if (s[l] == 'O' && s[l+1] == 'l' && s[l+2] == 'y' && s[l+3] == 'a')
            is[2] += 1;
    }
    for (int l = 0; l + 4 <  s.size(); l++)
        if (s[l] == 'S' && s[l+1] == 'l' && s[l+2] == 'a' && s[l+3] == 'v' && s[l+4] == 'a')
            is[3] += 1;
    for (int l = 0; l + 2 < s.size(); l++)
        if (s[l] == 'A' && s[l+1] == 'n' && s[l+2] == 'n')
            is[4] += 1;
    for (int l = 0; l + 5 < s.size(); l++)
        if (s[l] == 'N' && s[l+1] == 'i' && s[l+2] == 'k' && s[l+3] == 'i' && s[l+4] == 't' && s[l+5] == 'a')
            is[5] += 1;


    int kol = 0;
    for (int i = 0; i < 6; i++)
        kol += is[i];
    if (kol == 1)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}