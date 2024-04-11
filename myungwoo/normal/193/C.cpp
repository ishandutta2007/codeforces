#include <stdio.h>

int M,K,A[6],E[6],T[6][7],P[7],ans=1e9;
int mat[6][6]={
    0,1,1,0,1,1,
    1,0,1,1,0,1,
    0,0,1,1,1,0,
    1,1,0,1,1,0,
    0,1,0,1,0,1,
    1,0,0,0,1,1
};
char path[7][9]={"aaab","aaba","abaa","baaa","aabb","abab","abba"},O[4][600005];

inline void swap(int &a,int &b){ a ^= b, b ^= a, a ^= b; }

inline void row_swap(int a,int b)
{
    int i;
    for (i=0;i<7;i++) swap(T[a][i],T[b][i]);
}

bool proc()
{
    int i,j,k,v;
    for (i=0;i<6;i++){
        if (!T[i][i]){
            for (j=i;j<6;j++) if (T[j][i]){
                row_swap(i,j);
                break;
            }
        }
        if (!T[i][i]) return 0;
        v = T[i][i];
        for (j=0;j<7;j++){
            if (T[i][j]%v != 0) return 0;
            T[i][j] /= v;
        }
        for (j=0;j<6;j++) if (i != j && T[j][i]){
            v = T[j][i];
            for (k=0;k<7;k++) T[j][k] -= v*T[i][k];
        }
    }
    for (i=0;i<6;i++) if (T[i][6] < 0) return 0;
    return 1;
}

int main()
{
    int i,j,k;
    for (i=0;i<6;i++) scanf("%d",A+i);
    M = A[2];
    if (M > A[4]) M = A[4];
    if (M > A[5]) M = A[5];
    for (i=0;i<=M;i++){
        for (j=0;j<6;j++) for (k=0;k<6;k++) T[j][k] = mat[j][k];
        for (j=0;j<6;j++) T[j][6] = A[j];
        T[2][6] -= i, T[4][6] -= i, T[5][6] -= i;
        if (!proc()) continue;
        k = i;
        for (j=0;j<6;j++) k += T[j][6];
        if (ans > k){
            ans = k;
            P[0] = i;
            for (j=1;j<7;j++) P[j] = T[j-1][6];
        }
    }
    if (ans == 1e9){ puts("-1"); return 0; }
    printf("%d\n",ans);
    for (i=0;i<7;i++){
        while (P[i]--){
            for (j=0;j<4;j++) O[j][K] = path[i][j];
            K++;
        }
    }
    for (i=0;i<4;i++) puts(O[i]);
}