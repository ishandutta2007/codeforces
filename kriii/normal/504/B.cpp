#include <stdio.h>

int cnt[200002];
int rep[200002];
int N,A[200002];

const int Z = 1 << 18;
int down[Z*2];

void in(int x, int p)
{
    for (;x<=N;x+=x&(-x)) cnt[x] += p;
}

int out(int x)
{
    int r = 0;
    for (;x;x-=x&(-x)) r += cnt[x];
    return r;
}

int main()
{
    scanf ("%d",&N);
    for (int k=0;k<2;k++){
        for (int i=0;i<N;i++) scanf ("%d",&A[i]), A[i]++;

        for (int i=0;i<=N;i++) cnt[i] = 0;
        for (int i=1;i<=N;i++) in(i,1);

        for (int i=0;i<N;i++){
            in(A[i],-1);
            rep[N-i-1] += out(A[i]);
        }
    }

    for (int i=0;i<N;i++){
        int on = i + 1;
        if (rep[i] >= on){
            rep[i+1]++;
            rep[i] -= on;
        }
    }

    for (int i=0;i<N;i++) down[i+Z] = 1;
    for (int i=Z-1;i>=0;i--) down[i] = down[i*2] + down[i*2+1];
    for (int i=N-1;i>=0;i--){
        int w = rep[i]+1, x = 1;
        while (x < Z){
            down[x]--;
            x *= 2;
            if (down[x] < w) w -= down[x++];
        }
        down[x]--;
        printf ("%d ",x-Z);
    }

    return 0;
}