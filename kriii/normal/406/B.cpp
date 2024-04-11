#include <stdio.h>

int N,M,C,chk[1000001];

int main()
{
    scanf ("%d",&N); for (int i=0;i<N;i++){
        int x;
        scanf ("%d",&x);
        chk[x] = 1;
    }

    for (int i=1;i<=500000;i++){
        if (chk[i] == 1 && chk[1000001-i] == 1) C++;
        else if (chk[i] == 1) chk[1000001-i] = 2, M++;
        else if (chk[1000001-i] == 1) chk[i] = 2, M++;
    }

    for (int i=1;i<=500000;i++){
        if (C == 0) break;
        if (chk[i] == 0 && chk[1000001-i] == 0){
            chk[i] = chk[1000001-i] = 2; M += 2; C--;
        }
    }

    printf ("%d\n",M);
    for (int i=1;i<=1000000;i++) if (chk[i] == 2) printf ("%d ",i);

    return 0;
}