#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

template <typename T> inline int get_bit ( const T &x, int index ) { return (int)((x >> index) & 1); }
#define foreach(i,c) for ( typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i )
#define debug(x) cerr << #x << " = " << (x) << endl;

int bitrev(int x) {
  int res = 0;
  for (int i=0; i<8; ++i) {
    if (get_bit(x, i)) {
      res |= 1<<(7-i);
    }
  }
  return res;
}

int mod(int x) {
  return (x%256 + 256) % 256;
}

int main() {
  cin.sync_with_stdio(0);

  string input;
  getline(cin, input);
  for (int i=0; i<(int)input.size(); ++i) {
    int last = i > 0 ? input[i-1] : 0;
    cout << mod(bitrev(last) - bitrev(input[i])) << "\n";
  }

  return 0;
}