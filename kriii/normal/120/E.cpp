#include <stdio.h>

int T,N;

int main()
{
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);

    scanf ("%d",&T); while (T--){
        scanf ("%d",&N);N++;
        printf ("%d\n",N%2);
    }

    return 0;
}