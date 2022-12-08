#include <stdio.h>

int n,T,A[105],D[303],C[303];

int main()
{
    scanf ("%d %d",&n,&T);
    for (int i=0;i<n;i++) scanf ("%d",&A[i]), C[A[i]]++;
    int R = 0;
    if (T > 1000){
        R = T - 1000;
        T = 1000;
    }

    if (R == 0){
        for (int i=0;i<n*T;i++){
            int r = 0, x = A[i%n];
            for (int j=0;j<=x;j++) if (r < D[j]) r = D[j];
            r++;
            if (D[x] < r)
                D[x] = r;
        }
    }
    else{
        T = 500;
        for (int i=0;i<n*T;i++){
            int r = 0, x = A[i%n];
            for (int j=0;j<=x;j++) if (r < D[j]) r = D[j];
            r++;
            if (D[x] < r)
                D[x] = r;
        }
        int u = 0;
        for (int i=0;i<=300;i++){
            if (u < D[i]) u = D[i];
            if (D[i] < u + C[i] * R)
                D[i] = u + C[i] * R;
        }
        for (int i=0;i<n*T;i++){
            int r = 0, x = A[i%n];
            for (int j=0;j<=x;j++) if (r < D[j]) r = D[j];
            r++;
            if (D[x] < r)
                D[x] = r;
        }
    }

    int u = 0;
    for (int i=0;i<=300;i++){
        if (u < D[i]) u = D[i];
    }
    printf ("%d\n",u);

    return 0;
}