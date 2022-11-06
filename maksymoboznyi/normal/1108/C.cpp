#include <iostream>

using namespace std;

const int N = 1e5 + 5;

int n, kol[3][3], k[3];
string s;

int main()
{
    cin >> n;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'B')
            s[i] = 0;
        if (s[i] == 'R')
            s[i] = 1;
        if (s[i] == 'G')
            s[i] = 2;
    }
    for (int i = 0; i < s.size(); i++)
        k[i % 3]++, kol[i % 3][s[i]]++;
    int ans = 1000000;
    string S = s;
    for (int f = 0; f < 3; f++)
        for (int s = 0; s < 3; s++)
            for (int t = 0; t < 3; t++)
                if (s != t && t != f && s != f) {
                    int x = ans;
                    ans = min(ans, k[0] - kol[0][f] + k[1] - kol[1][s] + k[2] - kol[2][t]);
                    if (ans < x)
                        for (int i = 0; i < S.size(); i++)
                            if (i % 3 == 0)
                                S[i] = f;
                            else if (i % 3 == 1)
                                S[i] = s;
                            else
                                S[i] = t;
                }
    cout << ans << endl;
    s = S;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 0)
            cout << 'B';
        if (s[i] == 1)
            cout << 'R';
        if (s[i] == 2)
            cout << 'G';
    }
    return 0;
}