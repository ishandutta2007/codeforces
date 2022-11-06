#include <bits/stdc++.h>

using namespace std;
struct cell
{
    int v;
    int t;
};
cell ans[100];
cell p[5];
cell c[5];
cell w[5];
bool cmp(cell a, cell b)
{
    return a.v > b.v;
}
int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'R')
        {
            c[1].v++;
            p[1].v = i % 4+1;
        }
        if (s[i] == 'B')
        {
            c[2].v++;
            p[2].v = i % 4+1;
        }
        if (s[i] == 'Y')
        {
            c[3].v++;
            p[3].v = i%4+1;
        }
        if (s[i] == 'G')
        {
            c[4].v++;
            p[4].v = i %4+1;
        }
    }
    p[1].t = 1;
    p[2].t = 2;
    p[3].t = 3;
    p[4].t = 4;

    sort(p + 1, p + 5, cmp);
    //cout << p[4].t << ' ' ;
    if (s.size() % 4 == 0)
    {
        for (int i = 1; i < 5; i++)
            w[i].v = s.size() / 4;
    }
    if (s.size() % 4 == 1)
    {
        w[p[4].t].v = s.size() / 4 + 1;
        for (int i = 1; i < 4; i++)
            w[p[i].t].v = s.size() / 4;
    }
    if (s.size() % 4 == 2)
    {
        w[p[4].t].v = s.size() / 4 + 1;
        w[p[3].t].v = s.size() / 4 + 1;
        for (int i = 1; i < 3; i++)
            w[p[i].t].v = s.size() / 4;
    }
    if (s.size() % 4 == 3)
    {
        w[p[4].t].v = s.size() / 4 + 1;
        w[p[3].t].v = s.size() / 4 + 1;
        w[p[2].t].v = s.size() / 4 + 1;
        for (int i = 1; i < 2; i++)
            w[p[i].t].v = s.size() / 4;
    }
    cout << w[1].v - c[1].v << ' ' << w[2].v - c[2].v << ' ' << w[3].v - c[3].v << ' ' << w[4].v - c[4].v;
    return 0;
}