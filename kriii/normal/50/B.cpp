#include <stdio.h>
#include <string.h>

char STR[111110];
__int64 A[26],D[10];

int main()
{
    int i,l; __int64 S = 0;

    scanf ("%s",STR); l = strlen(STR);
    for (i=0;i<l;i++){
        if ('a' <= STR[i] && STR[i] <= 'z') A[STR[i]-'a']++;
        if ('0' <= STR[i] && STR[i] <= '9') D[STR[i]-'0']++;
    }

    for (i=0;i<26;i++) S += A[i] * A[i];
    for (i=0;i<10;i++) S += D[i] * D[i];
    printf ("%I64d",S);

    return 0;
}