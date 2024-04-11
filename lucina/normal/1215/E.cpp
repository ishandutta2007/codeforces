#include<bits/stdc++.h>
using namespace std;
const int maxn = 4e5+10;
int n,a[maxn], ct[21];
long long inv[21][21];
long long dp[(1 << 21)];
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
        --a[i];
    }
    ///pre-cal inversion
    for(int i=1;i<=n;i++){
        for(int j=0;j<20;j++){
            inv[a[i]][j] += ct[j];
        }
        ct[a[i]]++;
    }
    ///inv[x][y] = number of swaps require is x is next to y
    long long const inf = 1e18;
    for(int i=1;i<(1<<20);i++)
        dp[i] = inf;
    long long toadd = 0;
    int cur = 1;
    for(int i=0;i<20;i++){
        dp[cur] = ct[i];
        cur <<= 1;
    }
    int const mask = (1<<20);
    vector<int> c;
    for(int i=0;i<mask;i++){
            c.clear();
        for(int j=0;j<20;j++){
            if(i & (1<<j))
            c.push_back(j);
        }
        for(int j=0;j<20;j++){
            if(i & (1 << j))continue;
            toadd = 0;
            for(int k: c){
                toadd += inv[k][j];
            }
            dp[i | (1<<j)] = min(dp[i | (1<<j)],dp[i] +  toadd);
        }
    }
    printf("%lld\n",dp[mask-1]);
}
/*
    Good Luck
        -Lucina
*/