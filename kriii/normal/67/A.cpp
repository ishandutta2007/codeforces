#include <stdio.h>

int N,C[1010]; char O[1010];

int main()
{
    int i,j;

    scanf ("%d %s",&N,O+1); C[0] = 1;
    for (i=1;i<N;i++){
        if (O[i] == 'R') C[i] = C[i-1] + 1;
        else if (O[i] == '=') C[i] = C[i-1];
        else{
            C[i] = 1;
            for (j=i-1;j>=0;j--){
                if (O[j+1] == 'R'){
                    if (C[j] < C[j+1]) break;
                    C[j] = C[j+1] - 1;
                }
                else if (O[j+1] == '='){
                    if (C[j] == C[j+1]) break;
                    C[j] = C[j+1];
                }
                else{
                    if (C[j] > C[j+1]) break;
                    C[j] = C[j+1] + 1;
                }
            }
        }
    }

    for (i=0;i<N;i++) printf ("%d ",C[i]);

    return 0;
}