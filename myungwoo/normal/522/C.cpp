#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int T, N, M;
int A[MAXN], B[MAXN], P[MAXN], Q[MAXN];

int main()
{
    for (scanf("%d", &T);T--;){
        scanf("%d%d", &N, &M);
        for (int i=1;i<=M;i++) scanf("%d", A+i);
        for (int i=1;i<N;i++) scanf("%d%d", P+i, Q+i), B[P[i]]++;
        bool sw = 0; int res = 0;
        for (int i=1;i<N;i++){
            if (!Q[i]){
                if (P[i]) A[P[i]]--;
                else res++;
            }else{
                if (!sw){
                    int mn = 2e9;
                    for (int i=1;i<=M;i++) if (!B[i] && A[i] <= res){
                        mn = min(mn, A[i]), A[i] = 0;
                    }
                    res -= mn;
                    sw = 1;
                }
                if (P[i]) A[P[i]]--;
                else res++;
            }
            B[P[i]]--;
        }
        for (int i=1;i<=M;i++) printf("%s", res >= A[i] ? "Y" : "N"); puts("");
    }
}