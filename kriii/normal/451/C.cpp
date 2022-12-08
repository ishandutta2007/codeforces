#include <stdio.h>

int main()
{
    int T;

    scanf ("%d",&T); while (T--){
        long long n,k,d1,d2;

        scanf ("%lld %lld %lld %lld",&n,&k,&d1,&d2);

        if (n % 3){
            puts("no");
        }
        else{
            if (k + d1 + d2 <= n){
                long long c = k + d1 + d2;
                if (c % 3 == 0){
                    c /= 3;
                    if (0 <= c - d1 && 0 <= c - d2 && c <= n / 3){
                        puts("yes");
                        continue;
                    }
                }
            }
            if (0 <= k + d1 - d2 && k + d1 - d2 <= n){
                long long c = k + d1 - d2;
                if (c % 3 == 0){
                    c /= 3;
                    if (0 <= c - d1 && c + d2 <= n / 3){
                        puts("yes");
                        continue;
                    }
                }
            }
            if (0 <= k - d1 + d2 && k - d1 + d2 <= n){
                long long c = k - d1 + d2;
                if (c % 3 == 0){
                    c /= 3;
                    if (0 <= c - d2 && c + d1 <= n / 3){
                        puts("yes");
                        continue;
                    }
                }
            }
            if (0 <= k - d1 - d2){
                long long c = k - d1 - d2;
                if (c % 3 == 0){
                    c /= 3;
                    if (c + d1 <= n / 3 && c + d2 <= n / 3){
                        puts("yes");
                        continue;
                    }
                }
            }
            puts("no");
        }
    }

    return 0;
}