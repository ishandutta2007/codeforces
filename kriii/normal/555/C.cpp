#include <stdio.h>
#include <algorithm>
#include <queue>
#include <functional>
#include <set>
#include <map>
using namespace std;

set<int> in;
map<int, int> re,d;
int N,M,X[200005],R[200005],V[200005],S[200005]; char D[200005];

int main()
{
    scanf ("%d %d",&N,&M);
    for (int i=1;i<=M;i++){
        scanf ("%d %*d %c",&X[i],&D[i]);
        re[X[i]] = 0;
    }
    X[M+1] = N+1;

    D[0] = 'U';
    D[M+1] = 'L';
    int c = 1;
    for (auto &p : re) p.second = c++;
    map<int, int> cnt;
    for (int i=1;i<=M;i++){
        if (cnt[X[i]]++ > 0){
            R[i] = -1;
        }
        else R[i] = re[X[i]], V[R[i]] = i;
    }
    in.insert(0); in.insert(c);
    V[c] = M+1;
    R[M+1] = c;

    for (int i=1;i<=M;i++){
        if (R[i] == -1){
            printf ("0\n");
            continue;
        }
        if (D[i] == 'U'){
            int r = *(in.lower_bound(R[i]));
            if (D[V[r]] == 'U') S[i] = S[V[r]];
            else S[i] = N+1-X[V[r]];
            printf ("%d\n",(N+1-X[i])-S[i]);
        }
        else{
            int l = *(in.upper_bound(R[i]).operator--());
            if (D[V[l]] == 'L') S[i] = S[V[l]];
            else S[i] = X[V[l]];
            printf ("%d\n",X[i]-S[i]);
        }
        in.insert(R[i]); d[R[i]] = D[i];
    }

    return 0;
}