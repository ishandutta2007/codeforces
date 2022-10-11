#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100005;

int n;
bool chk = false;
long long ans = 0, sta = 0, cnv = 0, a[N];
char s[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld ", a + i);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
    {
        switch (s[i])
        {
        case 'G':
            ans += 5 * a[i];
            cnv += 2 * a[i];
            sta += a[i];
            break;
        
        case 'W':
            ans += 3 * a[i];
            sta += a[i];
            chk = true;
            break;
        
        case 'L':
            ans += a[i];
            sta -= a[i];
            if (sta < 0)
            {
                ans -= sta * (chk ? 3 : 5);
                sta = 0;
            }
            break;
        }
        cnv = min(cnv, sta);
    }
    printf("%lld", ans - sta - cnv);
}