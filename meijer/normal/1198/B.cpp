#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

#define REP(a,b,c) for(ll a=ll(b); a<ll(c); a++)
#define RE(a,b) REP(a,0,b)
#define INF 1e18
#define pb push_back
#define fi first
#define se second

const ll MX=2e5;
int n, a[MX], q, qt, p, x;
int LAZY[MX*4];

void buildSeg(int p=0, int l=0, int r=n-1) {
  LAZY[p] = 0;
  if(l != r) {
    int m=(l+r)/2;
    buildSeg(p*2+1,l,m);
    buildSeg(p*2+2,m+1,r);
  }
}
void updateSeg(int i, int v, int lazy=0, int p=0, int l=0, int r=n-1) {
  LAZY[p] = max(LAZY[p], lazy);
  if(l == r) a[l] = max(a[l], LAZY[p]);
  if(i < l || i > r) return;
  if(i == l && i == r) {
    LAZY[p] = 0;
    a[l] = v;
  } else {
    int m=(l+r)/2;
    updateSeg(i,v,LAZY[p],p*2+1,l,m);
    updateSeg(i,v,LAZY[p],p*2+2,m+1,r);
    LAZY[p] = 0;
  }
}
int getSeg(int i, int lazy=0, int p=0, int l=0, int r=n-1) {
  LAZY[p] = max(LAZY[p], lazy);
  if(l == r) a[l] = max(a[l], LAZY[p]);
  if(i<l || i>r) return 0;
  if(i == l && i == r) {
    return a[l];
  } else {
    int m=(l+r)/2;
    int a=getSeg(i,LAZY[p],p*2+1,l,m);
    int b=getSeg(i,LAZY[p],p*2+2,m+1,r);
    LAZY[p] = 0;
    return a+b;
  }
}

int main() {
  cin>>n;
  RE(i,n) cin>>a[i];
  cin>>q;
  while(q--) {
    cin>>qt;
    if(qt == 1) {
      cin>>p>>x;
      updateSeg(p-1,x);
    } else {
      cin>>x;
      LAZY[0] = max(LAZY[0], x);
    }
  }
  RE(i,n) cout<<(i==0?"":" ")<<getSeg(i); cout<<endl;
}