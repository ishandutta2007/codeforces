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

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, int> PLI;
typedef vector<int> VI;

int n;
pair<PII, int> a[100010];
VI v[100010];
vector<long long> T[100010];
int st[100010];
int nv;
int id[100010];
int ni;

vector<PLI> findBestTwo(int h) {
  vector<PLI> res(0);
  if (h == 0) return res;
  PLI p = PLI(-1, -1);
  int ip;
  Rep (i, nv) if (h <= v[i].size()) {
    PLI z = PLI(T[i][h - 1], i);
    if (p < z) {
      p = z;
      ip = i;
    }
  }
  if (p != PLI(-1, -1)) res.push_back(p);
  p = PLI(-1, -1);
  Rep (i, nv) if (h <= v[i].size() && i != ip) {
    PLI z = PLI(T[i][h - 1], i);
    if (p < z) {
      p = z;
    }
  }
  if (p != PLI(-1, -1)) res.push_back(p);
  return res;
}

int main() {
  scanf("%d", &n);
  Rep (i, n) {
    scanf("%d%d", &a[i].fi.fi, &a[i].fi.se);
    a[i].fi.se = -a[i].fi.se;
    a[i].se = i + 1;
  }
  sort(a, a + n);
  Rep (i, n) a[i].fi.se = -a[i].fi.se;
  Rep (i, n) {
    int j = i;
    while (j < n && a[j].fi.fi == a[i].fi.fi) ++j;
    --j;
    VI z;
    For (t, i, j) z.push_back(a[t].fi.se);
    st[nv] = i;
    v[nv++] = z;
    i = j;
  }
  Rep (i, nv) {
    int ne = v[i].size();
    T[i].resize(ne);
    Rep (j, ne) {
      T[i][j] = v[i][j] + (j == 0 ? 0 : T[i][j - 1]);
    }
    if (ne > 50) {
      id[ni++] = i;
    }
  }
  long long result = 0;
  int bi, bj;
  int hi, hj;
  Rep (ii, ni) For (jj, ii + 1, ni - 1) {
    int i = id[ii];
    int j = id[jj];
    int ri, rj;
    int k = min(v[i].size(), v[j].size());
    long long t = T[i][k - 1] + T[j][k - 1];
    ri = rj = k;
    if (k < v[i].size()) t += T[i][k] - T[i][k - 1], ++ri;
    if (k < v[j].size()) t += T[j][k] - T[j][k - 1], ++rj;
    if (result < t) {
      result = t;
      bi = i;
      bj = j;
      hi = ri;
      hj = rj;
    }
  }
  For (h, 1, 60) {
    vector<PLI> v1 = findBestTwo(h);
    vector<PLI> v2 = findBestTwo(h - 1);
    Fit (i1, v1) Fit (i2, v1) if (i1->second != i2->second) {
      long long z = i1->first + i2->first;
      if (result < z) {
        result = z;
        bi = i1->second;
        bj = i2->second;
        hi = hj = h;
      }
    }

    Fit (i1, v1) Fit (i2, v2) if (i1->second != i2->second) {
      long long z = i1->first + i2->first;
      if (result < z) {
        result = z;
        bi = i1->second;
        bj = i2->second;
        hi = h;
        hj = h - 1;
      }
    }
  }
  cout << result << endl;
  cout << hi + hj << endl;
  VI out;
  int si = st[bi];
  int sj = st[bj];
  if (hi < hj) swap(si, sj), swap(hi, hj);
  while (hi > 0 || hj > 0) {
    if (hi > 0) out.push_back(a[si++].se), --hi;
    if (hj > 0) out.push_back(a[sj++].se), --hj;
  }
  Rep (i, out.size()) printf("%d ", out[i]);
  return 0;
}