#include <stdio.h>
#include <vector>
using namespace std;

vector<int> G[111];

int T,N,L;
int Q[111],C[111],K[111];

int main()
{
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    int i,x,y;

    scanf ("%d",&T); while (T--){
        scanf ("%d",&N);
        for (i=1;i<=N;i++) G[i].clear();
        for (i=1;i<N;i++){
            scanf ("%d %d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
        }

        int head,tail;

        for (i=1;i<=N;i++) K[i] = 0;
        head = tail = -1; ++head; Q[head] = 1; K[1] = 1;
        while (head > tail){
            tail++; x = Q[tail];
            for (i=0;i<G[x].size();i++){
                y = G[x][i];
                if (K[y] == 0){
                    ++head; Q[head] = y; K[y] = 1;
                }
            }
        }

        for (i=1;i<=N;i++) K[i] = 0, C[i] = 0;
        head = tail = -1; ++head; Q[head] = x; K[x] = 1;
        while (head > tail){
            tail++; x = Q[tail];
            for (i=0;i<G[x].size();i++){
                y = G[x][i];
                if (K[y] == 0){
                    ++head; Q[head] = y; K[y] = 1; C[y] = C[x] + 1;
                }
            }
        }

        L += C[x];
    }

    printf ("%d",L);

    return 0;
}