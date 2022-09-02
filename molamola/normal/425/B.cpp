#include <cstdio>
#include <algorithm>
using namespace std;
 
int T, M, N, K, P[110][110];
int ans[10];
 
void colrev(int k)
{
    int i;
    for(i=0;i<M;i++)
        P[i][k]=!P[i][k];
    return;
}
 
int sum()
{
    int i, j, s=0, cnt;
    for(i=0;i<M;i++) {
        cnt=0;
        for(j=0;j<N;j++) {
            cnt+=P[i][j];
        }
        if(cnt>N/2) s+=N-cnt;
        else s+=cnt;
    }
    return s;
}
 
int crchk(int k)
{
    int sum1, sum2;
    sum1=sum();
    colrev(k);
    sum2=sum();
    if(sum1>sum2) return 1;
    colrev(k);
    return 0;
}
 
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int l, i, j, check;
    //scanf("%d", &T);
    T=1;
    for(l=1;l<=T;l++) {
        scanf("%d %d %d", &M, &N, &K);
        for(i=0;i<M;i++) {
            for(j=0;j<N;j++) {
                scanf("%d", &P[i][j]);
            }
        }
        for(i=1;i<=M;i++) {
            check=0;
            for(j=0;j<N;j++)
                check+=crchk(j);
            if(!check) break;
        }
        ans[l]=sum();
        if(ans[l]>K) ans[l]=-1;
    }
    for(l=1;l<=T;l++)
        printf("%d\n", ans[l]);
    return 0;
}