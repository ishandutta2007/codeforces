#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int N;
char S[100005],T[100005];
long long u[100005][2][2];

int main()
{
    scanf ("%d",&N);
    scanf ("%s %s",S+1,T+1);
    u[0][0][0] = 1;
    for (int i=1;i<=N+1;i++){
        for (int p=0;p<2;p++) for (int q=0;q<2;q++) if (i > p && i > q){
            if (S[i-p] == T[i-q]){
                u[i][p][q] += u[i-1][p][q];
            }
            else{
                if (p == 0) u[i][1][q] += u[i-1][p][q];
                if (q == 0) u[i][p][1] += u[i-1][p][q];
            }
        }
    }
    printf ("%lld\n",u[N+1][1][1]);

    return 0;
}