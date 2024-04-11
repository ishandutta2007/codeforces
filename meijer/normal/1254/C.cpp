#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(ll a=ll(b); a<ll(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(ll a=ll(c-1); a>=ll(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second
 
const ll MX=2000, MOD=1e9+7;
ll n, m, mxI, u;
vi ans, areaL, areaR;
vi left1, left2;
vi right1, right2;
ll SA[MX];
 
ll getArea(ll i, ll j, ll k) {
	cout<<1<<" "<<i<<" "<<j<<" "<<k<<endl;
	cout.flush();
	ll a;
	cin>>a;
	return a;
}
bool isLeft(ll i, ll j, ll k) {
	cout<<2<<" "<<i<<" "<<j<<" "<<k<<endl;
	cout.flush();
	ll a;
	cin>>a;
	return a==-1;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    vi left, right;
    REP(i,3,n+1) {
      if(isLeft(1,2,i)) left.pb(i);
      else right.pb(i);
    }
    for(ll i:left ) areaL.pb(getArea(1,2,i));
    for(ll i:right) areaR.pb(getArea(1,2,i));
    
    //left
    left1.pb(1);
    if(left.size() != 0) {
      mxI=0;
      m = areaL.size();
      RE(i,m) if(areaL[i] > areaL[mxI]) mxI = i;
      RE(i,m) SA[i] = i;
      sort(SA, SA+m, [](ll i, ll j) {
        return areaL[i] < areaL[j];
      });
      u = left[mxI];
      RE(i,m) {
        if(left[SA[i]] == u) continue;
        if(isLeft(1,u,left[SA[i]])) left1.pb(left[SA[i]]);
        else left2.pb(left[SA[i]]);
      }
      left2.pb(u);
      reverse(left2.begin(), left2.end());
    }
    
    //right
    right1.pb(2);
    if(right.size() != 0) {
      mxI=0;
      m = areaR.size();
      RE(i,m) if(areaR[i] > areaR[mxI]) mxI = i;
      RE(i,m) SA[i] = i;
      sort(SA, SA+m, [](ll i, ll j) {
        return areaR[i] < areaR[j];
      });
      u = right[mxI];
      RE(i,m) {
        if(right[SA[i]] == u) continue;
        if(isLeft(2,u,right[SA[i]])) right1.pb(right[SA[i]]);
        else right2.pb(right[SA[i]]);
      }
      right2.pb(u);
      reverse(right2.begin(), right2.end());
    }
    
    cout<<0;
    for(ll i:left1 ) cout<<" "<<i;
    for(ll i:left2 ) cout<<" "<<i;
    for(ll i:right1) cout<<" "<<i;
    for(ll i:right2) cout<<" "<<i;
    cout<<endl;
}