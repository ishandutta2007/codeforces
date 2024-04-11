//problem 5;
//author : Sangsoo Park;
//Time Complexity : O(n sqrt n + k log n);
//Memory Complexity : O(k log n);

#include<stdio.h>
#include<map>
using namespace std;

const int MOD = 1e9 + 7;
typedef long long ll;

int n, k;
int nHr[2030][21];

map <int,int> M[2020];
int p[2020];

int main()
{
//  freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&k);
    int i, j;
    for(i=1;i<=k;i++){
        nHr[i][0] = 1;
        for(j=1;j<=20;j++)
            nHr[i][j] = (nHr[i-1][j] + nHr[i][j-1]) % MOD;
    }
    for(i=1;i<=n;i++)p[i] = i;
    for(i=2;i<=n;i++)
        for(j=i;j<=n;j+=i)
            while(p[j] % i == 0)M[j][i]++, p[j] /= i;

    int ans = 0;
    for(i=1;i<=n;i++){
        ll cnt = 1;
        map <int,int>::iterator it;
        for(it = M[i].begin();it != M[i].end();++it){
            cnt *= nHr[k][it->second];
            cnt %= MOD;
        }
        ans = (ans + cnt) % MOD;
    }
    printf("%d",ans);
    return 0;
}