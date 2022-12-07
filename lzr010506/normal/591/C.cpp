#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 500005;
int a[N], b[N], n;

int main()
{
    while (scanf("%d", &n) == 1)
    {
        for (int i = 0; i < n; i ++)
            scanf("%d", &a[i]);
        int res = 0;
        for (int i = 1; i < n; i ++)
        {
            if (a[i] == 0 && a[i - 1] == 1)
            {
                int st = i - 1, en = i;
                i ++;
                while (i < n && a[i] != a[i - 1])
                {
                    en ++;
                    i ++;
                }
                int temp = en - st + 1;
                if (temp == 2)
                {
                    b[i - 2] = a[i - 2];
                    b[i - 1] = a[i - 1];
                    b[i] = a[i];
                    continue;
                }
                res = max(res, (temp - 1) / 2);
                if (temp % 2 == 0)
                {
                    int eenn = (st + en) / 2;
                    for (int j = st; j <= eenn; j++)
                        b[j] = 1;
                    for (int j = eenn + 1; j <= en; j++)
                        b[j] = 0;
                }
                else
                    for (int j = st; j <= en; j++)
                        b[j] = 1;
            }
            else if (a[i] == 1 && a[i - 1] == 0)
            {
                int st = i - 1, en = i;
                i ++;
                while (i < n && a[i] != a[i - 1])
                {
                    en ++;
                    i ++;
                }
                int temp = en - st + 1;
                if (temp == 2)
                {
                    b[i - 2] = a[i - 2];
                    b[i - 1] = a[i - 1];
                    b[i] = a[i];
                    continue;
                }
                res = max(res, (temp - 1) / 2);
                if (temp % 2 == 0)
                {
                    int eenn = (st + en) / 2;
                    for (int j = st; j <= eenn; j++)
                        b[j] = 0;
                    for (int j = eenn + 1; j <= en; j++)
                        b[j] = 1;
                }
                else 
                    for (int j = st; j <= en; j++)
                        b[j] = 0;
            }
            else 
                b[i - 1] = a[i - 1];
        }
        b[0] = a[0];
        printf("%d\n", res);
        for (int i = 0; i < n - 1; i++)
            printf("%d ", b[i]);
        printf("%d\n", a[n - 1]);
    }
    return 0;
}