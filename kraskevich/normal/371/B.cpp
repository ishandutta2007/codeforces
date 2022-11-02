#include <bits/stdc++.h>

using namespace std;

const long long INF = (long long)1e18;

int main()
{
    ios_base::sync_with_stdio(0);

    long long a, b;
    cin >> a >> b;
    long long res = INF;
    for (int i1 = 0; i1 <= 30; i1++)
        for (int i2 = 0; i2 <= 20; i2++)
            for (int i3 = 0; i3 <= 14; i3++)
            {
                long long fa = a;
                bool ok = true;
                for (int t = 0; t < i1; t++)
                {
                    if (fa % 2)
                        ok = false;
                    fa /= 2;
                }
                for (int t = 0; t < i2; t++)
                {
                    if (fa % 3)
                        ok = false;
                    fa /= 3;
                }
                for (int t = 0; t < i3; t++)
                {
                    if (fa % 5)
                        ok = false;
                    fa /= 5;
                }
                if (!ok)
                    break;
                for (int j1 = 0; j1 <= 30; j1++)
                    for (int j2 = 0; j2 <= 20; j2++)
                        for (int j3 = 0; j3 <= 14; j3++)
                        {
                            long long fb = b;
                            ok = true;
                            for (int t = 0; t < j1; t++)
                            {
                                if (fb % 2)
                                    ok = false;
                                fb /= 2;
                            }
                            for (int t = 0; t < j2; t++)
                            {
                                if (fb % 3)
                                    ok = false;
                                fb /= 3;
                            }
                            for (int t = 0; t < j3; t++)
                            {
                                if (fb % 5)
                                    ok = false;
                                fb /= 5;
                            }
                            if (ok && fa == fb)
                                res = min(res, 0ll + i1 + i2 + i3 + j1 + j2 + j3);
                        }
            }
    if (res == INF)
        res = -1;
    cout << res;

    return 0;
}