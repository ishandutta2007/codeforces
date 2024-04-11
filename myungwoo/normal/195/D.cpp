#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAXN 100005
typedef long long lld;

int N,M,ans;

struct Z{
    lld k,b;
    double my;
    bool operator < (const Z &ot)const{
        if (k*ot.k > 0) return -b*ot.k < -ot.b*k;
        else return -b*ot.k > -ot.b*k;
    }
} A[MAXN];

int main()
{
    int i,k,b;
    lld sum=0,psum;
    scanf("%d",&N);
    for (i=1;i<=N;i++){
        scanf("%d%d",&k,&b);
        if (k) A[++M].k = k, A[M].b = b;
    }
    sort(A+1,A+M+1);
    for (i=1;i<=M;i++){
        if (A[i].k < 0) sum += A[i].k;
    }
    psum = sum;
    for (i=1;i<=M;i++){
        if (A[i].k < 0) sum -= A[i].k;
        else sum += A[i].k;
        if (i < M && A[i].b*A[i+1].k == A[i+1].b*A[i].k) continue;
        if (psum != sum) ans++;
        psum = sum;
    }
    printf("%d",ans);
}