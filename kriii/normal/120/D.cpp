#include <stdio.h>
#include <vector>
using namespace std;
typedef vector<vector<int> > vii;

int right(vii& a, int A, int B, int C)
{
    int i,j,k,S,R,N=a.size(),M=a[0].size(),P=0;

    for (i=0;i<N;i++) for (j=1;j<M;j++) a[i][0] += a[i][j];

    S = 0;
    for (i=0;i<N;i++){
        S += a[i][0];
        R = 0;
        for (j=N-1;j>=i+2;j--){
            R += a[j][0];
            if ((S == A && R == B) || (S == A && R == C) ||
                (S == B && R == A) || (S == B && R == C) ||
                (S == C && R == B) || (S == C && R == A)) P++;
        }
    }

    return P;
}

int main()
{
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    int i,j,N,M,A,B,C;

    vii P,Q;
    scanf ("%d %d",&N,&M);
    P.resize(N);
    for (i=0;i<N;i++) P[i].resize(M);
    Q.resize(M);
    for (i=0;i<M;i++) Q[i].resize(N);

    int S = 0;
    for (i=0;i<N;i++){
        for (j=0;j<M;j++) scanf ("%d",&P[i][j]), Q[j][i] = P[i][j], S += P[i][j];
    }

    scanf ("%d %d %d",&A,&B,&C);
    if (S != A + B + C){printf ("0"); return 0;}

    int CNT = 0;
    CNT += right(P,A,B,C);
    CNT += right(Q,A,B,C);
    printf ("%d",CNT);

    return 0;
}