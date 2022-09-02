#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
#include<map>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

int nCr[4040][4040];

const int MOD = 1e9 +7;

int nHr(int n,int r){return nCr[n+r-1][r];}

int main()
{
    int i, j;
    nCr[0][0] = 1;
    nCr[1][0] = nCr[1][1] = 1;
    for(i=2;i<=4020;i++){
        nCr[i][0] = 1;
        for(j=1;j<=i;j++)nCr[i][j] = (nCr[i-1][j] + nCr[i-1][j-1])%MOD;
    }
    int n, k;
    scanf("%d%d",&n,&k);
    int ans = 0;
    for(i=1;i<=n;i++){
        map <int,int> M;
        int t = i;
        for(j=2;j<=n;j++){
            while(t%j == 0)M[j]++, t/=j;
        }
        if(t!=1)M[t]++;
        ll sum = 1;
        map <int,int>::iterator it;
        for(it = M.begin();it!=M.end();++it){
            sum *= nHr(k, it->second);
            sum %= MOD;
        }
        ans += sum;
        ans %= MOD;
    }
    printf("%d",ans);
    return 0;
}