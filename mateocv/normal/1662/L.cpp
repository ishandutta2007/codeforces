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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;

int lis(vector<ll>&v) {
  vi dp,list,logro;
  ll res=0;
  fore(i,0,SZ(v)){
    auto pos=upper_bound(ALL(dp),v[i]);
    if(pos==dp.end())dp.pb(v[i]),logro.pb(SZ(dp));
    else *pos=v[i],logro.pb(pos-dp.begin()+1);
    res=max(res,logro.back());
  }
  return res;
}

int main() {
  FIN;
  ll n, v; cin >> n >> v;
  vector<ll> times, places;
  fore(i, 0, n) {
    ll t; cin >> t;
    times.pb(t);
  }
  fore(i, 0, n) {
    ll p; cin >> p;
    places.pb(p);
  }
  vector<ii> pairs;
  fore(i, 0, n) {
    if((abs(places[i]) + v - 1) / v <= times[i]) {
      pairs.pb({v * times[i] - places[i], v * times[i] + places[i]});
    }
  }
  sort(ALL(pairs));
  vector<ll> rest;
  for(auto x : pairs) rest.pb(x.snd);
  cout << lis(rest) << '\n';
}