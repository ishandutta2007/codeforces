#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
typedef long long lld;
typedef pair <int, int> pii;

#define bit(n) (1LL << (n))

int N, M;
lld leak[1<<20]; double D[1<<20];
char S[51][21];

int main()
{
    scanf("%d", &N);
    for (int i=1;i<=N;i++) scanf("%s", S[i]);
    M = strlen(S[1]);
    for (int i=1;i<N;i++) for (int j=i+1;j<=N;j++){
        int msk = 0;
        for (int k=0;k<M;k++) if (S[i][k] == S[j][k])
            msk |= bit(k);
        leak[msk] |= bit(i) | bit(j);
    }
    for (int msk=bit(M);msk--;){
        for (int i=0;i<M;i++) if (!(msk & bit(i)))
            leak[msk] |= leak[msk | bit(i)];
    }
    double ans = 0;
    D[0] = 1;
    for (int msk=0;msk<bit(M);msk++){
        int cnt = 0;
        for (int j=0;j<M;j++) cnt += (bool)(msk & bit(j));
        for (int j=0;j<M;j++) if (!(msk & bit(j))){
            int nmsk = msk | bit(j);
            double nxt_prob = D[msk] / (M-cnt);
            lld smsk = leak[msk] ^ leak[nmsk];
            int scnt = 0;
            for (;smsk;smsk^=(smsk&(-smsk))) scnt++;
            ans += nxt_prob * (cnt + 1) * scnt / N;
            if (leak[nmsk]) D[nmsk] += D[msk] / (M-cnt);
        }
    }
    printf("%.12f\n", ans);
}