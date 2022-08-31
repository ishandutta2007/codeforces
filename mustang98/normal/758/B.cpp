#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100005;

int main()
{
    //ifstream cin("input.txt");
    string s;
    cin >> s;
    int lb, lg, ly, lr;
    lb = lg = ly = lr = -150;
    int kb, kr, kg, ky;
    kb = kr = kg = ky = 0;
    int m[5] = {0};
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'R')
        {
            lr = i % 4;
            m[lr] = 1;
        }
        if (s[i] == 'Y')
        {
            ly = i % 4;
            m[ly] = 1;
        }
        if (s[i] == 'B')
        {
            lb = i % 4;
            m[lb] = 1;
        }
        if (s[i] == 'G')
        {
            lg = i % 4;
            m[lg] = 1;
        }
    }
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] != '!') continue;
        if (i % 4 == lr)
        {
            kr++;
        }
        if (i % 4 == ly)
        {
            ky++;
        }
        if (i % 4 == lb)
        {
            kb++;
        }
        if (i % 4 == lg)
        {
            kg++;
        }
    }

    cout << kr << ' ' << kb << ' ' << ky << ' ' << kg;

    return 0;
}