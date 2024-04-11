#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e18
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

const int MX=2e5;
const int LEFT=0;
const int RIGHT=1;

ll n, m, k, q;
ll r[MX], c[MX];
ll tl[MX], tr[MX];
ll leftSave[MX], rightSave[MX];
ll NEXTI[MX];
ll mem[MX][2];
bitset<MX> safe;

ll getAns(ll i, ll t) {
    if(mem[i][t] == -1) {
        ll ni = NEXTI[i];
        ll dist=INF;
        if(ni != -1) {
            if(t == LEFT) {
                dist=min(dist, getAns(ni, LEFT )+abs(tr[i]-leftSave [tr[i]])+abs(tl[ni]-leftSave [tr[i]]));
                dist=min(dist, getAns(ni, LEFT )+abs(tr[i]-rightSave[tr[i]])+abs(tl[ni]-rightSave[tr[i]]));
                dist=min(dist, getAns(ni, RIGHT)+abs(tr[i]-leftSave [tr[i]])+abs(tr[ni]-leftSave [tr[i]]));
                dist=min(dist, getAns(ni, RIGHT)+abs(tr[i]-rightSave[tr[i]])+abs(tr[ni]-rightSave[tr[i]]));
            } else {
                dist=min(dist, getAns(ni, LEFT )+abs(tl[i]-leftSave [tl[i]])+abs(tl[ni]-leftSave [tl[i]]));
                dist=min(dist, getAns(ni, LEFT )+abs(tl[i]-rightSave[tl[i]])+abs(tl[ni]-rightSave[tl[i]]));
                dist=min(dist, getAns(ni, RIGHT)+abs(tl[i]-leftSave [tl[i]])+abs(tr[ni]-leftSave [tl[i]]));
                dist=min(dist, getAns(ni, RIGHT)+abs(tl[i]-rightSave[tl[i]])+abs(tr[ni]-rightSave[tl[i]]));
            }
        } else {
            dist = 0;
        }
        dist += tr[i]-tl[i];
        if(ni != -1)
            dist += ni-i;
        mem[i][t] = dist;
    }
    return mem[i][t];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>k>>q;
    REP(i,0,n)
        tl[i]=INF, tr[i]=-INF;
    REP(i,0,k) {
        cin>>r[i]>>c[i]; r[i]--; c[i]--;
        tl[r[i]]=min(tl[r[i]], c[i]);
        tr[r[i]]=max(tr[r[i]], c[i]);
    }
    int ni=-1;
    REP(i,0,n) {
        int j=n-i-1;
        NEXTI[j] = ni;
        if(tl[j] != INF) ni = j;
    }

    //fill save
    safe.reset();
    REP(i,0,q) {
        int b; cin>>b; b--;
        safe[b] = 1;
    }
    ll ls=-INF, rs=INF;
    REP(i,0,m) {
        if(safe[i]) ls=i;
        leftSave[i] = ls;
        ll j = m-i-1;
        if(safe[j]) rs=j;
        rightSave[j] = rs;
    }

    REP(i,0,n)
        REP(j,0,2)
            mem[i][j]=-1;

    if(ni == 0) {
        cout<<getAns(0, LEFT)+tl[0]<<endl;
    } else {
        ll dist=INF;
        dist=min(dist, getAns(ni, LEFT )+rightSave[0]+abs(tl[ni]-rightSave[0]));
        dist=min(dist, getAns(ni, RIGHT)+rightSave[0]+abs(tr[ni]-rightSave[0]));
        dist+=ni;
        cout<<dist<<endl;
    }
}