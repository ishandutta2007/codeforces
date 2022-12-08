#include <stdio.h>

int L; char S[101];

int main()
{
    scanf ("%d %s",&L,S);
    for (int i=1;i<=L;i++){
        for (int j=0;j<i;j++){
            int c = 0;
            for (int k=j;k<L;k+=i){
                if (S[k] == '*') c++;
                else c = 0;
                if (c >= 5){
                    puts("yes");
                    return 0;
                }
            }
        }
    }
    puts("no");

    return 0;
}