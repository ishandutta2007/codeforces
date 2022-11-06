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
    string a, b; cin >> a >> b;
    if(SZ(a) % 2 != SZ(b) % 2) cout << "NO\n";
    else {
      int cnta[3],cntb[3]; mset(cnta, 0); mset(cntb, 0);
      for(auto c : a) cnta[c-'A']++;
      for(auto c : b) cntb[c-'A']++;
      bool can = 1;
      fore(i, 0, 3) can = can && (cnta[i] % 2 == cntb[i] % 2);
      if(!can) cout << "NO\n";
      else {
        vector<char> A, B;
        for(auto c : a) if(c != 'B') {
          if(SZ(A) && A.back() == c) A.pop_back();
          else A.pb(c);
        }
        for(auto c : b) if(c != 'B') {
          if(SZ(B) && B.back() == c) B.pop_back();
          else B.pb(c);
        }
        if(A == B) cout << "YES\n";
        else cout << "NO\n";
      }
    }
  }
}