#include <stdio.h>

char S[1000001];
int N,K,pi[20][1000001],ls[1000001];

int main()
{
    scanf ("%d %d",&N,&K);
    scanf ("%s",S);

    for (int i=0;i<20;i++) pi[i][0] = -1; int k = -1;
    if (K == 1) putchar('1');
    else putchar('0');
    for (int i=1;S[i];i++){
        while (k >= 0 && S[i] != S[k+1]) k = pi[0][k];
        if (S[i] == S[k+1]) k++;
        pi[0][i] = k; ls[i] = k;
        for (int j=1;j<20;j++){
            if (pi[j-1][i] == -1) pi[j][i] = -1;
            else pi[j][i] = pi[j-1][pi[j-1][i]];
        }

        bool good = false;
        int p = i;
        for (int j=19;j>=0;j--){
            int ab = i - pi[j][p];
            int a = (i+1) % ab;
            int g = (i+1-a) / ab;
            if (g > K){
                if (p == -1) break;
                p = pi[j][p];
            }
            else if (g == K){
                good = true;
                break;
            }
        }
        if ((i + 1) % (K + 1) == 0){    
            int p = i;
            for (int j=19;j>=0;j--){
                int ab = i - pi[j][p];
                if (ab == (i + 1) / (K + 1)){ good = 1; break; }
                else if (ab < (i + 1) / K){
                    if (p == -1) break;
                    p = pi[j][p];
                }
            }
        }

        if (good) putchar('1');
        else putchar('0');
    }

    return 0;
}