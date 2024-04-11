#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

const long long MOD = 1000000007;
map<int, int> CNT;
map<int, int>::iterator I;
int N,K,U;
long long INV[100005];
long long FACT[100005];
long long FACTI[100005];
long long C[100005];
vector<long long> W;

bool islucky(int x)
{
    if (x == 0) return false;
    while (x){
        if (x % 10 != 4 && x % 10 != 7) return false;
        x /= 10;
    }
    return true;
}

int main()
{
    int j,c,t; long long i;

    scanf ("%d %d",&N,&K);
    for (i=0;i<N;i++){
        scanf ("%d",&c); CNT[c]++;
    }
    W.push_back(0);
    for (I=CNT.begin();I!=CNT.end();I++){
        c = I->first; t = I->second;
        if (islucky(c)) W.push_back(t);
        else U += t;
    }

    INV[1] = 1;
    for (i=2;i<=N;i++) INV[i] = (MOD - MOD / i) * INV[MOD % i] % MOD;

    FACT[0] = FACTI[0] = 1;
    for (i=1;i<=N;i++){
        FACT[i] = (FACT[i-1] * i) % MOD;
        FACTI[i] = (FACTI[i-1] * INV[i]) % MOD;
    }

    C[0] = 1;
    for (i=1;i<W.size();i++){
        for (j=i;j>=1;j--) C[j] = (C[j] + C[j-1] * W[i]) % MOD;
    }

    long long ANS = 0, TEMP;
    for (i=0;i<=K;i++){
        if (U < i) break;
        TEMP = FACT[U] * FACTI[i] % MOD;
        TEMP = TEMP * FACTI[U-i] % MOD;
        TEMP = TEMP * C[K-i] % MOD;
        ANS = (ANS + TEMP) % MOD;
    }
    printf ("%lld",ANS);

    return 0;
}