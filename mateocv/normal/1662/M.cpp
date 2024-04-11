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

int main() {
  FIN;
  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    int a = 0, b = 0;
    fore(i, 0, m) {
      int r, w; cin >> r >> w;
      a = max(r, a), b = max(w, b);
    }
    if(a + b > n) cout << "IMPOSSIBLE" << '\n';
    else {
      fore(i,0,a)cout<<"R";
      fore(i,0,b)cout<<"W";
      fore(i,a+b,n)cout<<"W";
      cout<<'\n';
    }
  }
}