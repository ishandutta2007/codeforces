#include <bits/stdc++.h>
using namespace std;
int T, n, m, a[100010];

int main() 
{
    scanf("%d", &T) ;
    while(T --)
	{
        scanf("%d%d", &n, &m);
        if (n == 1) 
		{
            puts("Yes");
            printf("%d\n", m);
            continue;
        }
        if (n > m) {puts("No"); continue;}
        else 
		{
            for (int i = 1; i <= n; i ++) a[i] = 1;
            m -= n;
            if (n & 1) 
			{
				puts("Yes");
                a[n] += m;
                for (int i = 1; i <= n; i ++) printf("%d%c", a[i], " \n"[i == n]);
            }
            else 
			{
                if (m & 1) puts("No");
                else 
				{
                    puts("Yes");
                    a[n] += (m >> 1); 
					a[n - 1] += (m >> 1);
                    for (int i = 1; i <= n; i ++) printf("%d%c", a[i], " \n"[i == n]);
                }
            }
        }
    }

    return 0;
}