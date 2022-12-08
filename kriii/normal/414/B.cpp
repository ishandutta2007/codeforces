#include <stdio.h>
#include <vector>
using namespace std;

const int mod = 1000000007;
long long D[2020][2020];
vector<pair<int, int> > see[2020];

int main()
{
    int N,K;

    scanf ("%d %d",&N,&K);
    for (int n=1;n<=N;n++) D[1][n] = 1;
    for (int l=2;l<=K;l++){
        for (int n=1;n<=N;n++){
            for (int d=1;n*d<=N;d++){
                D[l][n*d] = (D[l][n*d] + D[l-1][n]) % mod;
            }
        }
    }
    long long ans = 0;
    for (int n=1;n<=N;n++) ans = (ans + D[K][n]) % mod;
    printf ("%lld\n",ans);

    return 0;
}