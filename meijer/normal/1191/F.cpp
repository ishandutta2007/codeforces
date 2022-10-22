#include <iostream>
#include <cstdio>
#include <cmath>
#include <math.h>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <complex>
#include <map>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef complex<int> vec;
#define X real()
#define Y imag()
#define INF 1e9
#define EPS 1e-9
#define PI 2*acos(0)
#define REP(i, a, b) for(int i = int(a); i != int(b); i++)

ll n, x, y;
vec polls[200005];
map<ll, ll> xCoords;
bitset<200005> exists;
ll ft[200005];

ll lsb(ll i) {return (i & -i);}
ll rsq(ll i) {
    ll sm=0;
    while(i) sm += ft[i], i-=lsb(i);
    return sm;
}
ll rsq(ll i, ll j) {
    return rsq(j) - (i==1 ? 0 : rsq(i-1));
}
void update(ll i, ll v) {
    while(i <= n) ft[i] += v, i+=lsb(i);
}
bool comp1(vec a, vec b) {
    if(a.Y != b.Y) return a.Y > b.Y;
    return a.X < b.X;
}
bool comp2(vec a, vec b) {
    if(a.X != b.X) return a.X < b.X;
    return a.Y < b.Y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    REP(i,0,n) cin>>x>>y, polls[i]={x,y};
    sort(polls, polls+n, comp2);
    ll j = xCoords[polls[0].X] = 1;
    REP(i,1,n) xCoords[polls[i].X] = polls[i].X == polls[i-1].X ? j : ++j;
    REP(i,0,n+1) ft[i] = 0;
    sort(polls, polls+n, comp1);
    ll ans = 0; y = 1e19;
    exists.reset();
    REP(i,0,n) {
        if(polls[i].Y < y) {
            y=polls[i].Y;
            if(i!=0) ans += rsq(xCoords[polls[i-1].X]) * rsq(xCoords[polls[i-1].X], n);
        } else {
            ans += rsq(xCoords[polls[i-1].X]) * rsq(xCoords[polls[i-1].X], xCoords[polls[i].X]-1);
        }
        if(!exists[xCoords[polls[i].X]])
            update(xCoords[polls[i].X], 1), exists.set(xCoords[polls[i].X]);
    }
    ans += rsq(xCoords[polls[n-1].X]) * rsq(xCoords[polls[n-1].X], n);
    cout<<ans<<endl;
}