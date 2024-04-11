#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<string> V[111];
int N,T,M,A[111][2],B[111][2],D[111][111];
char E[111][22]; int P[111],C[111];

int main()
{
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    int i;

    scanf ("%d %d",&N,&T);
    for (i=0;i<N;i++) scanf ("%d %d %d %d",&A[i][0],&B[i][0],&A[i][1],&B[i][1]);
    scanf ("%d",&M);
    for (i=0;i<M;i++) scanf ("%s %d",E[i],&P[i]);

    int j=0,k=0,e=0,R; i = 0;
    while (k < M){
        R = T;
        while (R){
            while (C[e]) e = (e + 1) % M;
            int t = max(1,P[e]-(A[i][j]+B[i][!j])-D[i][e]);
            if (t > R){
                D[i][e] += R; e = (e + 1) % M; break;
            }
            else{
                V[i].push_back(E[e]); C[e] = 1; R -= t; k++;
                if (k == M) break;
            }
        }

        i++;
        if (i >= N){
            i = 0; j++;
            if (j == 2) j = 0;
        }
    }

    for (i=0;i<N;i++){
        printf ("%u ",V[i].size());
        for (j=0;j<V[i].size();j++) printf ("%s ",V[i][j].c_str());
        printf ("\n");
    }

    return 0;
}