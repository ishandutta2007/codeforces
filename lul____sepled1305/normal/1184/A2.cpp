#include <cstdio>
char s[222222];
int ans;
int q[222222];
int GCD(int a, int b)
{
    if(a*b == 0) return a+b;
    if(a < b) return GCD(b, a);
    return GCD(b, a%b);
}
main()
{
    int n; scanf("%d", &n);
    scanf("%s", s);
    for(int k = 1;k <= n;k++)
    {
        if(q[GCD(k, n)] == 0)
        {
            bool x = true;
            for(int i = 0;x && i < GCD(k, n);i++)
            {
                int sum = 0, j = i;
                do
                {
                    sum += s[j] - '0';
                    j = (j+k)%n;
                }while(j != i);
                if(sum%2) x = false;
            }
            if(x) q[GCD(k, n)] = 1, ans++;
            else q[GCD(k, n)] = -1;
        }
        else if(q[GCD(k, n)] == 1) ans++;
    }
    printf("%d\n", ans);
}