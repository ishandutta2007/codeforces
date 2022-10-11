#include <iostream>
#include <cstdio>
using namespace std;

const int N = 200005;

int n, b, a[N];
bool chk[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    int pt = 1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b);
        if (chk[b])
            printf("0 ");
        else
        {
            int ans = 0;
            while (pt <= n && a[pt] != b)
            {
                ans++;
                chk[a[pt++]] = true;
            }
            ans++;
            chk[a[pt++]] = true;
            printf("%d ", ans);
        }
    }
}