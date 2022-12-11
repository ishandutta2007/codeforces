#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    long long w, h, ww, hh, h1, h2, wa = 0, ha = 0, w1, w2;
    cin >> h >> w;
    for (ww = 1; ww <= w; ww *= 2)
    {
        h1 = floor(ww * 1.25 + 0.0001);
        h2 = ceil(ww * 0.8 + 0.0001);
        if (h2 > h) continue;
        if (h >= h1) hh = h1;
        else hh = h;
        if (hh * ww > wa * ha)
        {
            wa = ww;
            ha = hh;
        }
        if (hh * ww == wa * ha && hh > ha)
        {
            wa = ww;
            ha = hh;
        }
    }
    for (hh = 1; hh <= h; hh *= 2)
    {
        w1 = floor(hh * 1.25 + 0.0001);
        w2 = ceil(hh * 0.8 + 0.0001);
        if (w2 > w) continue;
        if (w >= w1) ww = w1;
        else ww = w;
        //cout << hh << " " << ww << endl;
        if (hh * ww > wa * ha)
        {
            wa = ww;
            ha = hh;
        }
        if (hh * ww == wa * ha && hh > ha)
        {
            wa = ww;
            ha = hh;
        }
    }
    cout << ha << " " << wa;
    return 0;
}