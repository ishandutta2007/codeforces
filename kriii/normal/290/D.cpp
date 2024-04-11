#include <stdio.h>

char S[100];
int x;

int main()
{
    scanf ("%s",S);
    scanf ("%d",&x);
    int i;

    for (i=0;i<S[i];i++) if ('A' <= S[i] && S[i] <= 'Z') S[i] += 'a' - 'A';
    for (i=0;i<S[i];i++){
        if (S[i] < x + 97)
            S[i] += 'A' - 'a';
    }
    printf ("%s",S);

    return 0;
}