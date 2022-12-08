#include <stdio.h>
#include <map>
using namespace std;

int N,K,A[5050];

int main()
{
    scanf ("%d %d",&N,&K);
    for (int i=0;i<N;i++) scanf ("%d",&A[i]);

    map<int, int> chk; chk[0] = 0;
    for (int i=0;i<N;i++){
        for (int j=1;j<=K;j++){
            if (!chk.count(A[i]*j)) chk[A[i]*j] = j;
            else{
                int &a = chk[A[i]*j];
                if (a > j)
                    a = j;
            }
        }
    }

    int Q; scanf ("%d",&Q); while (Q--){
        int ans = 1000;
        int x; scanf ("%d",&x);
        for (int i=0;i<N;i++){
            for (int j=1;j<=K;j++){
                if (A[i] * j > x) break;
                if (chk.count(x-A[i]*j)){
                    int use = chk[x-A[i]*j] + j;
                    if (use > K) continue;
                    if (ans > use)
                        ans = use;
                }
            }
        }
        if (ans == 1000)
            ans = -1;
        printf ("%d\n",ans);
    }

    return 0;
}