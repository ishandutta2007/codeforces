#include <bits/stdc++.h>
using namespace std;

vector<int> par;
vector<vector<int> > g;
vector<int> depth;
vector<int> flat;
vector<int> flatInd;

void flatten(int n, int d=0) {
  depth[n] = d;
  flatInd[n] = flat.size();
  flat.push_back(n);
  for (int c : g[n]) {
    flatten(c, d+1);
    flat.push_back(n);
  }
}

struct Rmq {
  Rmq(const vector<int>& v) :
    vRef(v),
    data(1, v) {
    for (int i=0; i<v.size(); ++i)
      data[0][i] = i;
    for (int j=0; (1<<j)<v.size(); ++j) {
      data.push_back(vector<int>(v.size()));
      for (int i=0; i+(1<<j)<v.size(); ++i) {
        data[j+1][i] = best(data[j][i], data[j][i+(1<<j)]);
      }
    }
  }
  
  int best(int a, int b) {
    if (a == -1 || b == -1)
      return a+b+1;
    if (vRef[a] > vRef[b])
      return a;
    else
      return b;
  }
  
  int getMax(int l, int r) {
    if (r <= l)
      return -1;
    int i=0;
    while (l+(1<<(i+1)) <= r)
      i++;
     return best(data[i][l], data[i][r-(1<<i)]);
  }
  
  const vector<int>& vRef;
  vector<vector<int> > data;
};

int main() {
  int n, q;
  cin >> n >> q;
  par.resize(n+1);
  g.resize(n+1);
  for (int i=2; i<=n; ++i) {
    cin >> par[i];
    g[par[i]].push_back(i);
  }
  flatInd.resize(n+1);
  depth.resize(n+1);
  flatten(1);

  vector<int> flatDepth(flat.size());
  for (int i=0; i<flat.size(); ++i)
    flatDepth[i] = -depth[flat[i]];
  vector<int> minFlatInd(flatInd.size());
  for (int i=0; i<flatInd.size(); ++i)
    minFlatInd[i] = -flatInd[i];

  Rmq flatIndMinRQ(minFlatInd), flatIndMaxRQ(flatInd),
    flatDepthRMQ(flatDepth);
  for (int ta=0; ta<q; ++ta) {
    int l, r;
    cin >> l >> r;
    r++;
    int imin = flatIndMinRQ.getMax(l, r);
    int imin2 = flatIndMinRQ.best(flatIndMinRQ.getMax(l, imin), flatIndMinRQ.getMax(imin+1, r));
    int imax = flatIndMaxRQ.getMax(l, r);
    int imax2 = flatIndMaxRQ.best(flatIndMaxRQ.getMax(l, imax), flatIndMaxRQ.getMax(imax+1, r));
    int lcaRmin = flatDepthRMQ.getMax(flatInd[imin2], flatInd[imax]+1);
    int lcaRmax = flatDepthRMQ.getMax(flatInd[imin], flatInd[imax2]+1);
    //cout << imin << ' ' << imax << ' ' << imin2 << ' ' << imax2 << ' ' << flatDepth[lcaRmin] << ' ' << flatDepth[lcaRmax] << endl;
    if (-flatDepth[lcaRmin] > -flatDepth[lcaRmax]) {
      cout << imin << ' ' << -flatDepth[lcaRmin] << endl;
    } else {
      cout << imax << ' ' << -flatDepth[lcaRmax] << endl;
    }
  }
}