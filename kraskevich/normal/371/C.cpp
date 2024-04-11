#include <bits/stdc++.h>

using namespace std;

string s;
long long nb, ns, nc;
long long pb, ps, pc;
long long tot;
long long cb, cs, cc;

bool good(long long x)
{
    long long b = cb * x;
    long long s = cs * x;
    long long c = cc * x;
    b -= nb;
    s -= ns;
    c -= nc;
    if (b < 0)
        b = 0;
    if (s < 0)
        s = 0;
    if (c < 0)
        c = 0;
    return b * pb + s * ps + c * pc <= tot;
}

int main()
{
    ios_base::sync_with_stdio(0);

    string s;
    cin >> s;
    cb = cs = cc = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'B')
            cb++;
        if (s[i] == 'S')
            cs++;
        if (s[i] == 'C')
            cc++;
    }
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> tot;

    long long l = 0;
    long long r = (long long)1e13;
    while (l < r)
    {
        long long m = (l + r + 1) / 2;
        if (good(m))
            l = m;
        else
            r = m - 1;
    }
    cout << l;

    return 0;
}