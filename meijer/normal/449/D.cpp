#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=1e6, K=20, BS=1<<K, MOD=1e9+7;
int n, a[MX], A[BS];

ll modpow(ll x_, ll N_) {
    if(N_ == 0) return 1;
    ll a = modpow(x_,N_/2);
    a = (a*a)%MOD;
    if(N_%2) a = (a*x_)%MOD;
    return a;
}
int countBits(int bs) {
    int cnt=0;
    RE(i,K)
        if(bs&(1<<i))
            cnt++;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    RE(i,n) cin>>a[i];
    RE(i,BS) A[i]=0;
    RE(i,n) A[(~a[i])&(BS-1)]++;
    RE(i,K)
        RE(mask,BS)
            if(mask & (1<<i))
                A[mask] += A[mask^(1<<i)];
    int ans=0;
    RE(mask,BS)
        ans = (ans+(countBits(mask)%2?-1:1)*modpow(2,A[mask])+MOD)%MOD;
    cout<<ans<<endl;
}