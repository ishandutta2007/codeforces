#include <stdio.h>
#include <vector>
using namespace std;

vector<int> G[300050];
int N,M,C[300050];

int main()
{
    int i,j,x,y,c;

    scanf ("%d %d",&N,&M);

    for (i=0;i<M;i++){
        scanf ("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }

    for (i=1;i<=N;i++) C[i] = 0;

    while (1){
        bool f = true;
        for (i=1;i<=N;i++){
            c = 0;
            for (j=0;j<G[i].size();j++) if (C[G[i][j]] == C[i]) c++;

            if (c > 1) C[i] = !C[i], f = false;
        }
        if (f) break;
    }

    for (i=1;i<=N;i++) printf ("%d",C[i]);

    return 0;
}