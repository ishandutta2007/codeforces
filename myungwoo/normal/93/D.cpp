#include <stdio.h>

#define MOD 1000000007
typedef long long lld;

int L,R;

struct MAT{
    lld m[9][9];
    MAT operator * (const MAT &b)const{
        int i,j,k;
        MAT ret={0,};
        for (i=0;i<9;i++) for (j=0;j<9;j++){
            for (k=0;k<9;k++) ret.m[i][j] = (ret.m[i][j]+m[i][k]*b.m[k][j])%MOD;
        }
        return ret;
    }
} mat[30];

int dy(int n)
{
    if (!n) return 0;
    if (n == 1) return 4;
    if (n == 2) return 12;
    int i,ret=0; MAT m;
    bool sw=0;
    n--;
    for (i=0;i<30;i++) if ((n>>i)&1){
        if (!sw) m = mat[i], sw = 1;
        else m = m*mat[i];
    }
    ret = m.m[8][8]*4%MOD;
    for (i=0;i<8;i++) ret = (ret+m.m[8][i])%MOD;
    return ret;
}

int solve(int n)
{
    int ret=(dy(n)+dy((n+1)/2))%MOD;
    return ret&1?(ret+MOD)/2:ret/2;
}

void inc(int a,int b){ mat[0].m[a][b]++; }

int main()
{
    int i;
    inc(0,4), inc(1,5), inc(1,7), inc(2,6), inc(2,3), inc(3,7), inc(3,5);
    inc(4,0), inc(4,1), inc(5,0), inc(5,1), inc(6,2), inc(7,3), inc(7,6);
    for (i=0;i<9;i++) mat[0].m[8][i]++;
    for (i=1;i<30;i++) mat[i] = mat[i-1]*mat[i-1];
    scanf("%d%d",&L,&R);
    printf("%d",(solve(R)-solve(L-1)+MOD)%MOD);
}