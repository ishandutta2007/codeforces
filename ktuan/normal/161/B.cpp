#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define Fit(i,v) for(typeof(v.begin()) i=v.begin();i!=v.end();++i)
#define fi first
#define se second
#define pb push_back

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, int> PLI;
typedef vector<int> VI;

struct Data {
  int v;
  int t;
  int i;
  bool operator<(Data d) const {
    return v < d.v;
  }
};

int n, k;
vector<Data> a, b;
vector<Data> cart[1010];

int main() {
  cin >> n >> k;
  // cart.resize(k);
  long long price = 0;
  Rep (i,  n) {
    Data d;
    int t;
    cin >> d.v >> t;
    price += d.v * 2;
    d.t = t;
    d.i = i + 1;
    if (t == 1) a.pb(d);
    else b.pb(d);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int en = a.size() - 1;
  int st = max(0, en - k + 1);
  For (i, st, en) cart[i - st].pb(a[i]);

  int z = en - st + 1;
  
  Rep (i, st) {
    cart[0].pb(a[i]);
  }

  Rep (i, b.size()) {
    if (z < k) {
      cart[z++].pb(b[i]);
    } else {
      if (k <= a.size()) {
        cart[0].pb(b[i]);
      } else {
        cart[k - 1].pb(b[i]);
      }
    }
  }
  
  Rep (i, k) {
    sort(cart[i].begin(), cart[i].end());
    bool have = false;
    Fit (j, cart[i]) if (j->t == 1) have = true;
    if (have) price -= cart[i][0].v;
  }

  if (price % 2 == 0) cout << price / 2 << ".0" << endl;
  else cout << price / 2 << ".5" << endl;

  Rep (i, k) {
    cout << cart[i].size();
    Fit (j, cart[i]) cout << " " << (j->i);
    cout << endl;
  }
  return 0;
}