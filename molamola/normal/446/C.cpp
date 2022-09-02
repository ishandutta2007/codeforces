#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

const int MOD = 1e9 + 9;

int a[300030];
ll s[300030];
int n, m;
int bk = 700;
int qua[300030][3];

struct idxt{
    static const int T_ = 1<<19;
    ll T[T_<<1];
    void update(int s,int d,int v){
        s += T_, d += T_;
        while(s<=d){
            if(s&1)T[s] = (T[s] + v + MOD) % MOD;
            if(!(d&1))T[d] = (T[d] + v + MOD) % MOD;
            s = (s+1)>>1;
            d = (d-1)>>1;
        }
    }
    ll read(int x){
        x += T_;
        ll res = 0;
        while(x){
            res = (T[x] + res) % MOD;
            x >>= 1;
        }
        return res;
    }
}it;

ll s2[300030];
ll upd[300030];
ll F[300030];
int st[1000][2], top1;

void pre()
{
    int i, r, l;
    for(i=0;i<top1;i++){
        l = st[i][0], r = st[i][1];
        upd[l] += F[3];
        upd[l+1] += F[2];
        upd[r+1] = (upd[r+1] - F[r-l+4] + MOD) % MOD;
        upd[r+2] = (upd[r+2] - F[r-l+3] + MOD) % MOD;
    }
    s2[1] = upd[1];
    s2[2] = s2[1] + upd[2];
    for(i=3;i<=n;i++)s2[i] = (s2[i-1] + s2[i-2] + upd[i]) % MOD;
    for(i=1;i<=n;i++)s[i] = (s[i] + s2[i]) % MOD;
    for(i=1;i<=n;i++)upd[i] = 0;
    top1 = 0;
}

int main()
{
    scanf("%d%d",&n,&m);
    int i;
    for(i=1;i<=n;i++)scanf("%d",a+i);
    for(i=1;i<=n;i++)s[i] = s[i-1] + a[i];
    for(i=1;i<=m;i++)scanf("%d%d%d",qua[i],qua[i]+1,qua[i]+2);
    F[1] = 1, F[2] = 1;
    for(i=3;i<=300020;i++)F[i] = (F[i-1] + F[i-2]) % MOD;
    for(i=1;i<=m;i++){
        if(i % bk == 0){
            pre();
        }
        int l = qua[i][1];
        int r = qua[i][2];
        if(qua[i][0] == 1){
            it.update(l, n, -1);
            it.update(r+1, n, F[r-l+3]);
            st[top1][0] = l, st[top1++][1] = r;
        }
        else{
            ll ans = 0;
            ans = (s[r] - s[l-1] + MOD) % MOD;
            ans = (ans + it.read(r) - it.read(l-1) + MOD) % MOD;
            for(int j=0;j<top1;j++){
                if(st[j][0] <= r && r <= st[j][1])ans = (ans + F[r - st[j][0] + 3]) % MOD;
                if(st[j][0] <= l-1 && l-1 <= st[j][1])ans = (ans - F[l-1 - st[j][0] + 3] + MOD) % MOD;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}