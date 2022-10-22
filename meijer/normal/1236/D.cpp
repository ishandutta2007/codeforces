#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(ll a=ll(b); a<ll(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(ll a=ll(c-1); a>=ll(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const ll MX=2e5;
ll r, c, k, x, y;
ll dir=0;
set<ll> obstR[MX], obstC[MX];
const ll RIGHT=0, DOWN=1, LEFT=2, UP=3;

ll getFirst(ll x, ll y, ll dir) {
    switch(dir) {
        case RIGHT:{
            auto it = obstR[y].upper_bound(x);
            if(it != obstR[y].end()) return *it;
            else return c+1;}
        case DOWN:{
            auto it = obstC[x].upper_bound(y);
            if(it != obstC[x].end()) return *it;
            else return r+1;}
            break;
        case LEFT:{
            auto it = obstR[y].upper_bound(x);
            if(it != obstR[y].begin()) return *(--it);
            else return 0;}
            break;
        case UP:{
            auto it = obstC[x].upper_bound(y);
            if(it != obstC[x].begin()) return *(--it);
            else return 0;}
            break;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>r>>c>>k;
    RE(i,k) cin>>x>>y, obstR[x].insert(y), obstC[y].insert(x);

    ll most[4];
    most[LEFT]=0;most[UP]=1;
    most[RIGHT]=c+1,most[DOWN]=r+1;

    ll visited=1, x=1, y=1, dir=0;
    while(1) {
        ll nextPos = getFirst(x,y,dir);
        if(dir == LEFT)     nextPos = max(nextPos, most[LEFT])  +1;
        if(dir == RIGHT)    nextPos = min(nextPos, most[RIGHT]) -1;
        if(dir == UP)       nextPos = max(nextPos, most[UP])    +1;
        if(dir == DOWN)     nextPos = min(nextPos, most[DOWN])  -1;

        if(dir%2) visited += abs(y-nextPos), y = nextPos;
        else visited += abs(x-nextPos), x = nextPos;

        if(dir == LEFT) most[LEFT] = x;
        if(dir == RIGHT) most[RIGHT] = x;
        if(dir == UP) most[UP] = y;
        if(dir == DOWN) most[DOWN] = y;

        if(most[LEFT] >= most[RIGHT]) break;
        if(most[UP] >= most[DOWN]) break;

        dir = (dir+1)%4;
    }
    cout<<((visited == r*c - k)?"Yes":"No")<<endl;
}