#include <bits/stdc++.h>

#define F first
#define S second
#define prev privet1

using namespace std;

const int max_n = 500009;

char fig[max_n];
pair<int, int> pos[max_n];

int main()
{
    long long x, y, cx, cy;
    int n;
    char c;
    cin >> n;
    cin >> y >> x;
    long long  luy = y, ldy = y, llx = x, lrx = x;
    bool lr = false, ll = 0, ld = 0, lu = 0;
    long long sd1, sd2, sd3, sd4;
    bool s1 = 0, s2 = 0, s3 = 0, s4 = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> fig[i];
        c = fig[i];
        scanf("%I64d %I64d", &cy, &cx);
        //cout << c << endl;
        pos[i].F = cx;
        pos[i].S = cy;

        if (c == 'R' || c == 'Q')
        {
            if (cx == x)
            {
                if (cy > y)
                {
                    if (!lu)
                    {
                        lu = true;
                        luy = cy;
                    }
                    else
                    {
                        luy = min(luy, cy);
                    }
                }
                else
                {
                    if (!ld)
                    {
                        ld = true;
                        ldy = cy;
                    }
                    else
                    {
                        ldy = max(ldy, cy);
                    }
                }
            }

            if (cy == y)
            {
                if (cx > x)
                {
                    if (!lr)
                    {
                        lr = true;
                        lrx = cx;
                    }
                    else
                    {
                        lrx = min(lrx, cx);
                    }
                }
                else
                {
                    if (!ll)
                    {
                        ll = true;
                        llx = cx;
                    }
                    else
                    {
                        llx = max(llx, cx);
                    }
                }
            }
        }

        if (c == 'B' || c == 'Q')
        {
            if (abs(x - cx) != abs(y - cy)) continue;
            long long d = abs(x - cx);
            if (cx > x && cy > y)
            {
                if (!s1)
                {
                    s1 = true;
                    sd1 = d;
                }
                else
                {
                    sd1 = min(sd1, d);
                }
            }
            else if (cx > x && cy < y)
            {
                if (!s2)
                {
                    s2 = true;
                    sd2 = d;
                }
                else
                {
                    sd2 = min(sd2, d);
                }
            }
            else if (cx < x && cy < y)
            {
                if (!s3)
                {
                    s3 = true;
                    sd3 = d;
                }
                else
                {
                    sd3 = min(sd3, d);
                }
            }
            else if (cx < x && cy > y)
            {
                if (!s4)
                {
                    s4 = true;
                    sd4 = d;
                }
                else
                {
                    sd4 = min(sd4, d);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        c = fig[i];
        cx = pos[i].F;
        cy = pos[i].S;
        if (cx == x)
        {
            if (cy > y && lu)
            {
                if (cy < luy) lu = false;
            }
            else if (cy < y && ld)
            {
                if (cy > ldy) ld = false;
            }
        }
        if (cy == y)
        {
            if (cx > x && lr)
            {
                if (cx < lrx) lr = false;
            }
            else if (cx < x && ll)
            {
                if (cx > llx) ll = false;
            }
        }

        if (abs(cx - x) != abs(cy - y)) continue;
        long long d = abs(cx - x);
        if (cx > x && cy > y && s1)
        {
            if (d < sd1) s1 = false;
        }
        if (cx > x && cy < y && s2)
        {
            if (d < sd2) s2 = false;
        }
        if (cx < x && cy < y && s3)
        {
            if (d < sd3) s3 = false;
        }
        if (cx < x && cy > y && s4)
        {
            if (d < sd4) s4 = false;
        }
    }

    if (s1 || s2 || s3 || s4 || lu || ll || lr || ld)
    {
        cout << "YES";

    }
    else
    {
        cout << "NO";
    }

    return 0;
}