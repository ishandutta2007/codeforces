#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long lld;

lld MOD,L,R,K;
vector <lld> A;

struct MAT{
    lld m[2][2];
    MAT operator * (const MAT &b)const{
        MAT ret={0,};
        int i,j,k;
        for (i=0;i<2;i++) for (j=0;j<2;j++){
            for (k=0;k<2;k++) ret.m[i][j] = (ret.m[i][j]+(m[i][k]*b.m[k][j])%MOD)%MOD;
        }
        return ret;
    }
} D[66],T;

lld fib(lld n)
{
    int i,j;
    for (i=0;i<2;i++) T.m[i][i] = 1;
    D[0].m[0][0] = D[0].m[0][1] = D[0].m[1][0] = 1;
    for (i=1;i<66;i++) D[i] = D[i-1]*D[i-1];
    for (n--,i=0;n;i++,n>>=1) if (n&1){
        T = T*D[i];
    }
    return T.m[0][0]%MOD;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    int i;
    lld n;
    scanf("%lld%lld%lld%lld",&MOD,&L,&R,&K);
    for (n=1;n*n<=R;n++) A.push_back(n), A.push_back(R/n);
    sort(A.begin(),A.end());
    for (i=A.size();i--;){
        if (R/A[i]-(L-1)/A[i] >= K){
            printf("%lld",fib(A[i]));
            break;
        }
    }
}