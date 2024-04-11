#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MaxN = 300005,
          MaxK = 5005;

int N, K;
int tab[MaxN];
LL dp[MaxK][MaxK];

void input(){
    scanf("%d%d", &N, &K);
    for(int i = 0; i < N; i++){
        scanf("%d", &tab[i]);
    }
}

int main(){
    input();
    sort(tab, tab+N);

    int smallChain = N/K,
        largeChain = smallChain+1,
        numLarge   = N%K,
        numSmall   = K-numLarge;

    if(N % K == 0){
        numLarge = 0;
        numSmall = K;
    }

//    printf("large=%d small=%d\n", numLarge, numSmall);

    dp[0][0] = 0;
    for(int i = 1; i <= K; i++) dp[0][i] = 1e18;
    for(int packs = 1; packs <= K; packs++){
        for(int sPacks = 0; sPacks <= numSmall; sPacks++){
            if(sPacks > packs) continue;
            int last = packs*largeChain - sPacks - 1;
//            printf("last=%d\n", last);
            dp[packs][sPacks] = 1e18;

            if(last >= largeChain-1 && sPacks < packs){
                dp[packs][sPacks] = dp[packs-1][sPacks] + tab[last] - tab[last-largeChain+1];
            }

            if(sPacks > 0 && last >= smallChain-1){
                dp[packs][sPacks] = min(dp[packs][sPacks],
                        dp[packs-1][sPacks-1] + tab[last] - tab[last-smallChain+1]);
            }
        }
    }

    cout << dp[K][numSmall] << endl;
}