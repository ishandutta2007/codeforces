#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(ll a=ll(b); a<ll(c); a++)
#define INF 1e18

const ll MX=4e5, COLS=20, DP=(1<<COLS);
ll n;
ll a[MX];
vi idx[COLS];
ll cnt[COLS][COLS];
ll mem[DP];

ll getAns(ll bm) {
    if(mem[bm] == -1) {
        mem[bm] = INF;
        REP(i,0,COLS) {
            if((bm&(1<<i)) != 0) {
                ll nbm = bm&(~(1<<i)), sum=0;
                REP(j,0,COLS)
                    if((nbm&(1<<j)) != 0)
                        sum += cnt[j][i];
                mem[bm] = min(mem[bm], getAns(nbm)+sum);
            }
        }
    }
    return mem[bm];
}

int main() {
    cin>>n;
    REP(i,0,n) cin>>a[i], a[i]--;
    REP(i,0,n)
        idx[a[i]].push_back(i);
    REP(i,0,COLS) {
        REP(j,0,COLS) {
            cnt[i][j] = 0;
            if(i == j|| idx[j].size()==0) continue;
            ll l=0;
            REP(k,0,idx[i].size()) {
                while(l!=(ll)idx[j].size() && idx[j][l] < idx[i][k])
                    l++;
                cnt[i][j] += l;
            }
        }
    }
    REP(i,0,DP)
        mem[i]=-1;
    mem[0]=0;
    cout<<getAns(DP-1)<<endl;
}