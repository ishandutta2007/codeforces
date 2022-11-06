#include <bits/stdc++.h>
 
using namespace std;
 
#define fore(i, s, e) for(int i = s; i < e; i++)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define ALL(a) a.begin(),a.end()
#define pb push_back
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mset(a, b) memset(a, b, sizeof(a))
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

struct STree {
  vector<ii> t; int n;
  ii NEUT;
  STree(int n, ii NEUT):n(n),t(2*n+5,NEUT),NEUT(NEUT){}
  void upd(int p, ii v, ii f(ii, ii)){
    p+=n;
    for(t[p]=v;p>1;p>>=1)t[p>>1]=f(t[p],t[p^1]);
  }
  ii query(int l, int r, ii f(ii, ii)){
    ii res=NEUT;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
      if(l&1)res=f(res,t[l++]);
      if(r&1)res=f(res,t[--r]);
    }
    return res;
  }
};

ii my_min(ii a, ii b){return min(a,b);}
ii my_max(ii a, ii b){return max(a,b);}

int main() {
  FIN;
  int t; cin >> t;
  while(t--) {
    int n, a, b; cin >> n >> a >> b; a--, b--;
    int p[n]; fore(i, 0, n) cin >> p[i];

    STree izq(n, {-1e9, -1}), der(n, {1e9, -1});
    fore(i, 0, n) izq.upd(i, {i + p[i], i}, my_max), der.upd(i, {i - p[i], i}, my_min);
    int dist[n]; mset(dist, -1);
    queue<int> q; q.push(a); dist[a] = 0; izq.upd(a, {-1e9, -1}, my_max); der.upd(a, {1e9, -1}, my_min);
    while(!q.empty()) {
      auto x = q.front(); q.pop();
      ii query;
      do {
        query = izq.query(max(0, x - p[x]), x, my_max);
        if(query.fst >= x) {
          dist[query.snd] = dist[x] + 1;
          izq.upd(query.snd, {-1e9, -1}, my_max);
          der.upd(query.snd, {1e9, -1}, my_min);
          q.push(query.snd);
        }
      } while(query.fst >= x);

      do {
        query = der.query(x + 1, min(n, x + p[x] + 1), my_min);
        if(query.fst <= x) {
          dist[query.snd] = dist[x] + 1;
          izq.upd(query.snd, {-1e9, -1}, my_max);
          der.upd(query.snd, {1e9, -1}, my_min);
          q.push(query.snd);
        }
      } while(query.fst <= x);
    }
    cout << dist[b] << '\n';
  }
}