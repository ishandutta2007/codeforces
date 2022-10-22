#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(ll a=ll(b); a<ll(c); a++)

const ll MX=1100000;
const ll EMPTY=-INF-1;

ll n, w;
ll l, a;
ll SEG[MX*4];
ll LAST[MX*4];
ll COMBO[MX*4];

ll left (ll i) {return (i<<1)+1;}
ll right(ll i) {return (i<<1)+2;}
void buildSeg(ll p, ll l, ll r) {
    SEG[p] = 0;
    LAST[p] = -1;
    COMBO[p] = -1;
    if(l != r) {
        ll m=(l+r)/2;
        buildSeg(left(p),l,m);
        buildSeg(right(p),m+1,r);
    }
}
void addSeg(ll i, ll j, ll value, ll last, ll down=0, ll p=0, ll l=0, ll r=-1) {
    if(r == -1) r=w-1;
    if(j < i) return;

    SEG[p] += down;
    if(LAST[p] == last) return;
    if(j < l || i > r) return;
    if(i <= l && j >= r && COMBO[p] != last) {
        SEG[p] += value;
        LAST[p] = last;
        COMBO[p] = last;
    } else {
        ll m=(l+r)/2;
        addSeg(i,j,value,last,SEG[p],left(p) ,l  ,m);
        addSeg(i,j,value,last,SEG[p],right(p),m+1,r);
        COMBO[p] = max(COMBO[left(p)], COMBO[right(p)]);
        if(LAST[left(p)] == LAST[right(p)])
            LAST[p] = LAST[left(p)];
        SEG[p] = 0;
    }
}
ll getSeg(ll i, ll down, ll p, ll l, ll r) {
    SEG[p] += down;
    if(i < l || i > r) return 0;
    if(l == r) return SEG[p];

    ll m=(l+r)/2;
    ll a=getSeg(i,SEG[p],left(p),l,m);
    ll b=getSeg(i,SEG[p],right(p),m+1,r);
    SEG[p] = 0;
    return a+b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>w;
    buildSeg(0,0,w-1);
    REP(i,0,n) {
        cin>>l;
        priority_queue<ii, vector<ii>, less<ii>> pq;
        REP(j,0,l)
            cin>>a, pq.push({a,j});
        while(!pq.empty()) {
            ii p = pq.top(); pq.pop();
            ll v = p.first, pos = p.second;
            ll posEnd = w-(l-pos);
            if(v < 0) {
                posEnd  = min(posEnd, l-1);
                pos     = max(pos, w-l);
            }
            if(pos > posEnd) continue;
            addSeg(pos, posEnd, v, i);
        }
    }
    cout<<getSeg(0,0,0,0,w-1);
    REP(i,1,w)
        cout<<" "<<getSeg(i,0,0,0,w-1);
    cout<<endl;
}