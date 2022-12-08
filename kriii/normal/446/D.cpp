#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

double A[505][505],R[505][505],B[505][505],P[505],T[505],D[505],f[505][505];

int main()
{
    int N,M,K,n;

    scanf ("%d %d %d",&N,&M,&K); n = N;
    vector<bool> chk(N,0);
    for (int i=0;i<N;i++){
        int x; scanf ("%d",&x);
        chk[i] = x ? true : false;
    }

    for (int i=0;i<M;i++){
        int x,y; scanf ("%d %d",&x,&y); x--; y--;
        f[x][y] += 1; f[y][x] += 1; D[x] += 1; D[y] += 1;
    }
    for (int i=0;i<N;i++){
        A[i][i] = 1;
        for (int j=0;j<N;j++){
            if (!chk[j]){
                A[i][j] -= f[j][i]/D[j];
            }
        }
    }


    for (int i=0;i<n;i++) R[i][i] = 1;
    for (int i=0;i<n;i++){
        for (int j=i;j<n;j++){
            if (abs(A[j][i]) > 1e-6){
                for (int k=i;k<n;k++){
                    swap(A[i][k],A[j][k]);
                    swap(R[i][k],R[j][k]);
                }
                break;
            }
        }
        double u = A[i][i];
        for (int j=0;j<n;j++){
            A[i][j] /= u;
            R[i][j] /= u;
        }
        for (int j=0;j<n;j++) if (i != j){
            u = A[j][i];
            for (int k=0;k<n;k++){
                A[j][k] -= u * A[i][k];
                R[j][k] -= u * R[i][k];
            }
        }
    }
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) A[i][j] = R[i][j], R[i][j] = 0;

    int c = 0;
    for (int i=0;i<n;i++){
        if (chk[i]) P[c++] = A[i][0];
    }

    for (int i=0,p=0;i<n;i++) if (chk[i]){
        for (int j=0,q=0;j<n;j++) if (chk[j]){
            B[p][q] = 0;
            for (int k=0;k<n;k++) if (f[i][k] > 0) {
                if (!chk[k]) B[p][q] += f[i][k] * A[j][k] / D[i];
                else if (j == k) B[p][q] += f[i][k] / D[i];
            }
            q++;
        }
        p++;
    }

    K -= 2;
    while (K){
        if (K & 1){
            for (int i=0;i<c;i++) T[i] = 0;
            for (int i=0;i<c;i++) for (int j=0;j<c;j++) T[j] += P[i] * B[i][j];
            for (int i=0;i<c;i++) P[i] = T[i];
        }
        for (int i=0;i<c;i++) for (int j=0;j<c;j++) R[i][j] = 0;
        for (int i=0;i<c;i++) for (int j=0;j<c;j++) for (int k=0;k<c;k++) R[i][k] += B[i][j] * B[j][k];
        for (int i=0;i<c;i++) for (int j=0;j<c;j++) B[i][j] = R[i][j];
        K >>= 1;
    }
    printf ("%.10lf\n",P[c-1]);

    return 0;
}