#include <stdio.h>

char S[1000001],T[1000001];
int I[1000001],P[1000001],V[1000001],R[1000001];
int nx[1000001];

int main()
{
    int Q,L;
    scanf ("%s %d",S,&Q);
    for (L=0;S[L];L++);
    while (Q--){
        int d,k; scanf ("%d %d",&d,&k);

        if (d == 1){
            puts(S);
            continue;
        }
        for (int i=0,c=0;i<k;i++){
            for (int j=(i==0?k:i);j<d;j+=k) P[c++] = j;
        }
        P[d-1] = 0;

        int elen = 0, x = 0, ch = 0;
        R[elen++] = x;
        while (1){
            x = P[x];
            if (x == 0) break;
            R[elen++] = x;
        }

        for (int i=0;i<d;i++) nx[i] = i;
        int tr = L - d + 1; x = d-1;
        for (int i=0;i<tr-1;i++){
            x = P[x];
            nx[x] = R[elen++] = i+d;
        }
        int ort = tr;

        for (int i=0;i<d;i++) I[i] = i;
        while (tr){
            if (tr & 1){
                for (int i=0;i<d;i++) V[i] = P[I[i]];
                for (int i=0;i<d;i++) I[i] = V[i];
            }
            for (int i=0;i<d;i++) V[i] = P[P[i]];
            for (int i=0;i<d;i++) P[i] = V[i];
            tr /= 2;
        }
        for (int i=ort+1,j=1;i<L;i++,j++) R[i] = nx[I[j]];

        for (int i=0;i<L;i++) T[i] = S[R[i]];
        for (int i=0;i<L;i++) S[i] = T[i];
        puts(S);
    }

    return 0;
}