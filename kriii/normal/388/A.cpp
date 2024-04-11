#include <stdio.h>
#include <algorithm>
using namespace std;

int N,X[101],T[101];

int main()
{
    int i,j;

    scanf ("%d",&N);
    for (i=0;i<N;i++) scanf ("%d",&X[i]);
    sort(X,X+N);

    for (int pile=1;pile<=N;pile++){
        for (i=0;i<pile;i++) T[i] = 1;
        for (;i<N;i++){
            int mx = 0, ind = -1;
            for (j=0;j<pile;j++){
                if (X[i] >= T[j]){
                    if (mx < T[j]){
                        mx = T[j];
                        ind = j;
                    }
                }
            }
            if (ind == -1) break;
            T[ind]++;
        }
        if (i==N){
            printf ("%d\n",pile); break;
        }
    }

    return 0;
}