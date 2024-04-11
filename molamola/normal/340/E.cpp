#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
using namespace std;

const long long M = 1e9+7;
int p[2020];
int Dp[2020][2020];
bool check[2020];
bool check2[2020];
int a,b;

void solve()
{
    int i;
    long long tmp;
    for(i=2;i<=a;i++){
        tmp=(long long)i*Dp[i-1][0]+((i&1)?-1:1);
        Dp[i][0]=(int)(tmp%M);
    }
    Dp[0][1]=1;
    for(i=2;i<=b;i++){
        tmp=i*(long long)Dp[0][i-1];
        tmp%=M;
        Dp[0][i]=(int)tmp;
    }
    int j;
    for(i=1;i<=a;i++){
        for(j=1;j<=b;j++){
            tmp=(long long)i*Dp[i-1][j]+j*(long long)Dp[i][j-1];
            tmp%=M;
            Dp[i][j]=(int)tmp;
        }
    }
    printf("%d",Dp[a][b]);
}

int main()
{
    int N;scanf("%d",&N);
    int i;
    for(i=1;i<=N;i++){
        scanf("%d",p+i);
        if(p[i]==-1){
            a++;
            check2[i]=1;
        }
        else check[p[i]]=1;
    }
    for(i=1;i<=N;i++){
        if(check2[i] && check[i]){a--;b++;}
    }
    solve();
    return 0;
}