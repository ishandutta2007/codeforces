#include <iostream>
#include <algorithm>
using namespace std;


int a[500500];
bool used[500500];


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i] );
    sort(a, a + n);

    int ans = 0;
    int curup = (n + 1) / 2;
    for (int i = 0; i < n; i++)
    {
        if (used[i] )
            continue;
        ans++;
        used[i] = true;
        while (curup < n && a[i] * 2 > a[curup] )
            curup++;
        if (curup != n)
        {
            used[curup] = true;
            curup++;
        }
    }
    printf("%d\n", ans);





    return 0;
}