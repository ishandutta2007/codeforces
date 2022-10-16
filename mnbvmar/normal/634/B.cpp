#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

template<typename TH>
void debug_vars(const char* data, TH head){
    cerr << data << "=" << head << "\n";
}

template<typename TH, typename... TA>
void debug_vars(const char* data, TH head, TA... tail){
    while(*data != ',') cerr << *data++;
    cerr << "=" << head << ",";
    debug_vars(data+1, tail...);
}

#ifdef LOCAL
#define debug(...) debug_vars(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#endif

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

/////////////////////////////////////////////////////////

LL s, x;

void input(){
  cin >> s >> x;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  input();

  LL res = 1, mask = 0;

  for (LL a = 1; a < (1LL<<50); a *= 2) {
    if (x & a) {
      res <<= 1;
    } else {
      mask |= (2 * a);
    }
  }


  if (s < x) {
    cout << "0\n"; return 0;
  }

  if (s == x) {
    res -= 2;
  }

  if (((s - x) | mask) == mask) {
    cout << res << "\n";
  } else {
    cout << 0 << "\n";
  }

}