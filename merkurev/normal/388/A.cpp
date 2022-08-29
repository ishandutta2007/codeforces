#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



int a[105];
int cnt[105];
int boxes = 0;


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i] );
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        bool gd = false;
        for (int j = 0; j < boxes; j++)
        {
            if (cnt[j] <= a[i] )
            {
                cnt[j]++;
                gd = true;
                break;
            }
        }
        if (!gd)
        {
            cnt[boxes] = 1;
            boxes++;
        }
    }
    printf("%d\n", boxes);




    return 0;
}