#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100005;

int n, k, g, b;

void printanswer(int gpr, int bpr)
{
    int kolg = g / gpr;
    int kolb = b / bpr;
    int modg = g % gpr;
    int modb = b % bpr;

    bool isgr = false;
    if (gpr >= bpr) isgr = true;

    while(true)
    {
        if (isgr)
        {
            for (int i = 0; i < kolg; i++)
            {
                //if (g == 0) break;
                cout << 'G';
                g--;
            }
            if (modg)
            {
                cout << 'G';
                modg--;
                g--;
            }
        }
        else
        {
            for (int i = 0; i < kolb; i++)
            {
                //if (g == 0) break;
                cout << 'B';
                b--;
            }
            if (modb)
            {
                cout << 'B';
                modb--;
                b--;
            }
        }
        if (g == 0 && b == 0) return;
        isgr = !isgr;
    }
}

int main()
{
    cin >> n >> k >> g >> b;
    int kolg, kolb;
    if (g == 0)
    {
        if (b > k)
        {
            cout << "NO";
            return 0;
        }
        for (int i = 0; i < b; i++) cout << 'B';
        return 0;
    }
    if (b == 0)
    {
        if (g > k)
        {
            cout << "NO";
            return 0;
        }
        for(int i = 0; i < g; i++) cout << 'G';
        return 0;
    }
    for (int gpr = 1; gpr <= g; gpr++)
    {
        if (g % gpr == 0) kolg = g / gpr;
        else kolg = (g / gpr) + 1;

        for (int bpr = gpr - 1; bpr <= gpr + 1; bpr++)
        {
            if (bpr <= 0 || bpr > b) continue;
            if (b % bpr == 0) kolb = b / bpr;
            else kolb = (b / bpr) + 1;

            if (kolb <= k && kolg <= k && kolb > 0 && kolg > 0)
            {
                printanswer(gpr, bpr);
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}