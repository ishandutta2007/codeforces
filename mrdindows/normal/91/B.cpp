#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int a[100001];
int min_on_suf[100010];

int main()
{

    int n;
    scanf("%d",&n);

    for (int i=0;i<n;++i)
    {
        scanf("%d",&(a[i]));
    }

    min_on_suf[n-1] = a[n-1];
    for (int i=n-2;i>=0;--i)
    {
        min_on_suf[i] = min(min_on_suf[i+1], a[i]);
    }


    for (int i=0;i<n;++i)
    {
        int l = i + 1;
        int r = n;

        while (l != r)
        {
            int m = (l + r) / 2;
            if (min_on_suf[m] >= a[i])
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        int res = l - 1;
        if (res == i)
        {
            printf("-1 ");
        }
        else
        {
            printf("%d ",res-i-1);
        }
    }
    return 0;
}