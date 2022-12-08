#include <stdio.h>

long long ori[3][3],time[41][3][3];

int main()
{
    for (int i=0;i<3;i++) for (int j=0;j<3;j++) scanf ("%lld",&ori[i][j]), time[1][i][j] = ori[i][j];
    int N; scanf ("%d",&N);
    for (int s=1;s<=N;s++){
        if (s >= 2){
            for (int i=0;i<3;i++) for (int j=0;j<3;j++) if (i != j){
                time[s][i][j] = time[s-1][i][3-i-j] + ori[i][j] + time[s-1][3-i-j][j];
                long long u = time[s-1][i][j] + ori[i][3-i-j] + time[s-1][j][i] + ori[3-i-j][j] + time[s-1][i][j];
                if (time[s][i][j] > u)
                    time[s][i][j] = u;
            }
        }
        for (int k=0;k<3;k++) for (int i=0;i<3;i++) for (int j=0;j<3;j++) if (time[s][i][j] > time[s][i][k] + time[s][k][j]) time[s][i][j] = time[s][i][k] + time[s][k][j];
    }

    printf ("%lld\n",time[N][0][2]);

    return 0;
}