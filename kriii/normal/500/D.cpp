#include <stdio.h>
#include <vector>
#include<queue>
using namespace std;

vector<int> g[100001];
int N,x[100001],y[100001],w[100001]; double c[100001];
int Q[100001]; bool chk[100001]; int sz[100001];

int main()
{
    scanf ("%d",&N);
    for (int i=1;i<N;i++){
        scanf ("%d %d %d",&x[i],&y[i],&w[i]);
        g[x[i]].push_back(i);
        g[y[i]].push_back(i);
    }

    int head = -1, tail = -1;

    Q[++head] = 1; chk[1] = 1;
    while (tail < head){
        int p = Q[++tail];
        for (int i : g[p]){
            int q = x[i] == p ? y[i] : x[i];
            if (!chk[q]){
                Q[++head] = q; chk[q] = 1;
            }
        }
    }
    for (int t=N-1;t>=0;t--){
        int p = Q[t];
        sz[p] = 1;
        for (int i : g[p]){
            int q = x[i] == p ? y[i] : x[i];
            if (!chk[q]){
                sz[p] += sz[q];
            }
        }
        for (int i : g[p]){
            int q = x[i] == p ? y[i] : x[i];
            if (chk[q]) c[i] = 1. * sz[p] * (N - sz[p]);
        }
        chk[p] = 0;
    }

    double a = 0;
    for (int i=1;i<N;i++) a += c[i] * w[i];
    int Q; scanf ("%d",&Q); while (Q--){
        int i,d; scanf ("%d %d",&i,&d);
        a -= c[i] * w[i];
        w[i] = d;
        a += c[i] * w[i];
        printf ("%.12lf\n",a/N/(N-1)*6);
    }

    return 0;
}