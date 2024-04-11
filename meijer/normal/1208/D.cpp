#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

#define INF 1e18
#define REP(a,b,c) for(ll a=ll(b); a<ll(c); a++)

const ll MX = 250000;

ll n=0;
ll s[MX];
ll ans[MX];
ll RMQ[MX*4];
ll SEG[MX*4];
ll DOWN[MX*4];

int left (int i) {return (i<<1) + 1;}
int right(int i) {return (i<<1) + 2;}
void updateSeg(int p) {
    int a = RMQ[left(p)];
    int b = RMQ[right(p)];
    if(SEG[left(p)] == SEG[right(p)]) {
        if(a > b) {
            RMQ[p] = a;
            SEG[p] = SEG[left(p)];
        } else {
            RMQ[p] = b;
            SEG[p] = SEG[right(p)];
        }
    } else {
        if(SEG[left(p)] < SEG[right(p)]) {
            RMQ[p] = a;
            SEG[p] = SEG[left(p)];
        } else {
            RMQ[p] = b;
            SEG[p] = SEG[right(p)];
        }
    }
}
void buildSeg(int p, int l, int r) {
    DOWN[p] = 0;
    if(l == r) {
        RMQ[p] = l;
        SEG[p] = s[l];
    } else {
        int m = (l+r)/2;
        buildSeg(left(p), l, m);
        buildSeg(right(p), m+1, r);
        updateSeg(p);
    }
}
void rangeAdd(int i, int j, ll value, ll down, int p, int l, int r) {
    if(i > j) return;
    SEG[p]  += down;
    DOWN[p] += down;
    if(j < l || i > r) return;
    if(i <= l && j >= r) {
        DOWN[p] += value;
        SEG[p]  += value;
    } else {
        int mid = (l+r)/2;
        rangeAdd(i,j,value,DOWN[p],left(p),l,mid);
        rangeAdd(i,j,value,DOWN[p],right(p),mid+1,r);
        DOWN[p] = 0;
        updateSeg(p);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    REP(i,0,n) cin>>s[i];

    buildSeg(0,0,n-1);
    REP(a,1,n+1) {
        int i = RMQ[0];
        ans[i] = a;
        rangeAdd(i,i,INF,0,0,0,n-1);
        rangeAdd(i+1,n-1,-a,0,0,0,n-1);
    }
    cout<<ans[0];
    REP(i,1,n)
        cout<<" "<<ans[i];
    cout<<endl;
}