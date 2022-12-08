#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

int N,M,L,V[9],Y[9],C[9];
double ans = 0;

void go(int a, int c)
{
    int i,j;
    if (a == N){
        if (c) return;
        double res=0,p,E[9],c,A,B;
        for (i=0;i<N;i++){
            E[i] = Y[i] + C[i] * 10;
            if (E[i] > 100) E[i] = 100;
            E[i] = E[i] / 100;
        }

        for (i=0;i<(1<<N);i++){
            p = 1; c = 0; A = L; B = 0;
            for (j=0;j<N;j++){
                if (i & 1 << j){
                    c++; p *= E[j];// A += V[j];
                }
                else{
                    p *= 1 - E[j]; B += V[j];
                }
            }

            if (c > N / 2);
            else p *= A / (A + B);
            res += p;
        }
        ans = max(ans,res);
    }
    else{
        for (i=0;i<=c;i++){
            C[a] = i;
            go (a+1,c-i);
        }
    }
}

int main()
{
    int i;

    cin >> N >> M >> L;
    for (i=0;i<N;i++) cin >> V[i] >> Y[i];
    go(0,M);

    printf ("%.10lf",ans);

    return 0;
}