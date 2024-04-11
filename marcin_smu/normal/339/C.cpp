#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
typedef pair<int,int> PI;
typedef long long LL;
typedef double D;
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define R(I,N) for(int I=0;I<N;I++)
#define F(I,A,B) for(int I=A;I<B;I++)
#define FD(I,N) for(int I=N-1;I>=0;I--)
#define make(A) scanf("%d",&A)
#define makel(A) scanf("%I64d",&A)
#define pll(A) printf("%I64d ",A)
//#define makel(A) scanf("%lld",&A)
//#define pll(A) printf("%lld ",A)
char z[11];
int m;
int wyn[1001];
bool dp[1001][10][10];
void tak(int m,int j,int k){
    m--;
    if(m==-1)return;
    wyn[m]=j+1;
    R(l,10){
        if(j==l)continue;
        if(dp[m][l][j-k+1]){
            tak(m,l,j-k+1);
            return;
        }
    }
}
main(){
    scanf(" %s",z);
    make(m);
    R(i,10)
        dp[1][i][i+1] = (z[i]=='1');
    F(i,2,m+1)R(j,10)F(k,1,11){
        if(z[j]=='0' || j < k)continue;
        R(l,10){
            if(l==j)continue;
            if(dp[i-1][l][j-k+1])
            dp[i][j][k] = 1;
        }
    }
    R(i,10)R(j,11){
        if(dp[m][i][j]){
            tak(m,i,j);
            printf("YES\n");
            R(i,m)
                printf("%d ",wyn[i]);
            printf("\n");
            return 0;
        }
    }
    printf("NO\n");
}