#include <stdio.h>

int main()
{
    int n,k;

    scanf ("%d %d",&n,&k);

    if (n / 2 > k) printf ("-1");
    else if (n == 1){
        if (k > 0) printf ("-1");
        else printf ("1");
    }
    else{
        int c = 1;
        while (n > 3){
            printf ("%d %d ",c,c+1);
            c += 2; n -= 2; k--;
        }

        int p = 1000000000 / k;
        printf ("%d %d ",p*k,p*k-k); n -= 2;
        if (n == 1) printf ("%d",c);
    }

    return 0;
}