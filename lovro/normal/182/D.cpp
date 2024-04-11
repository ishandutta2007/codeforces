// BEGIN CUT HERE
// headers begin
// END CUT HERE
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
// BEGIN CUT HERE
// headers end
// END CUT HERE

using namespace std;

// BEGIN CUT HERE 
// helper functions begin
// END CUT HERE
// BEGIN CUT HERE 
// helper functions end
template<typename T> ostream& operator<<( ostream &os, const vector<T> &v ) { os << "{"; for ( typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " " << *vi; } os << " }"; return os; }
template<> ostream& operator<<( ostream &os, const vector<string> &v ) { os << "{"; for ( vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }
template<typename T, typename U> ostream& operator<<( ostream &os, const pair<T, U> &P ) { return os << "(" << P.first << ", " << P.second << ")"; }
template<typename T> ostream& operator<<( ostream &os, const set<T> &S ) { return os << vector<T>( S.begin(), S.end() ); }
template<typename T, typename U> ostream& operator<<( ostream &os, const map<T, U> &M ) { for ( typename map<T, U>::const_iterator mi=M.begin(); mi!=M.end(); ++mi ) { os << mi->first << " => " << mi->second << endl; } return os; }
// END CUT HERE

bool isdivisor(const string &hay, const string &need) {
  for (int i=0; i<(int)hay.size(); i+=(int)need.size()) {
    if (hay.compare(i, need.size(), need) != 0) {
      return false;
    }
  }
  return true;
}

int main() {
  cin.sync_with_stdio(0);

  string s1, s2;
  cin >> s1 >> s2;
  int maxlen = min(s1.size(), s2.size());
  int res = 0;
  for (int len=1; len<=maxlen; ++len) {
    if (s1.size() % len == 0 && s2.size() % len == 0) {
      string str = s1.substr(0, len);
      res += isdivisor(s1, str) && isdivisor(s2, str);
    }
  }
  cout << res << '\n';

  return 0;
}