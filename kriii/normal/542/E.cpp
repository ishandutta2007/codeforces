#include <stdio.h>
#include <vector>
using namespace std;

vector<int> G[1010];
int N,M,D[1010],Q[1010],T[1010],A; bool chk[1010];

int main()
{
    scanf ("%d %d",&N,&M);
    for (int i=0;i<M;i++){
        int x,y;
        scanf ("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }

    for (int i=1;i<=N;i++) if (!chk[i]){
        int head = -1, tail = -1, c = 0;
        Q[++head] = i; chk[i] = 1;
        while (tail < head){
            int x = Q[++tail]; c++;
            for (int y : G[x]) if (!chk[y]){
                Q[++head] = y; chk[y] = 1;
            }
        }
        int mx = -1;
        for (int j=0;j<c;j++){
            head = tail = -1;
            for (int k=1;k<=N;k++) D[k] = -1;
            T[++head] = Q[j]; D[Q[j]] = 0;
            bool good = 1; int d;
            while (tail < head){
                int x = T[++tail]; d = D[x];
                for (int y : G[x]){
                    if (D[y] == -1){
                        T[++head] = y; D[y] = D[x] + 1;
                    }
                    else if (D[x] == D[y]){
                        good = 0; break;
                    }
                }
                if (!good) break;
            }
            if (good){
                if (mx < d)
                    mx = d;
            }
        }
        if (mx == -1){
            A = -1;
            break;
        }
        A += mx;
    }
    printf ("%d\n",A);

    return 0;
}