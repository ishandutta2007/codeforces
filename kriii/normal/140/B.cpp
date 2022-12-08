#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

int N,U[333][333],L[333][333],P[333],V[333];

int main()
{
    int i,j,k;

    scanf ("%d",&N);
    for (i=1;i<=N;i++){
        for (j=1;j<=N;j++){
            scanf ("%d",&U[i][j]);
            L[i][U[i][j]] = j;
        }
    }
    for (j=1;j<=N;j++){
        scanf ("%d",&P[j]);
        V[P[j]] = j;
    }
    for (i=1;i<=N;i++){
        for (j=1;j<=N;j++){
            if (U[i][j] == i) continue;
            for (k=j+1;k<=N;k++){
                if (U[i][k] == i) continue;
                if (U[i][j] > U[i][k] && V[U[i][j]] > V[U[i][k]]) break;
            }
            if (k > N){printf ("%d ",U[i][j]); break;}
        }
    }

    return 0;
}