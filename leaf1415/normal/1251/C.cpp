#include <iostream>
#include <string>
#include <algorithm>
#define llint long long

using namespace std;

int T;
string s;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for(int z = 0; z < T; z++){
    cin >> s;
    string t, u;
    for(int i = 0; i < s.size(); i++){
      int x = s[i]-'0';
      if(x % 2) t += s[i];
      else u += s[i];
    }
    //sort(t.begin(), t.end());
    //sort(u.begin(), u.end());

    //cout << t << " " << u << endl;

    string ans; llint p = 0, q = 0;
    for(int i = 0; i < s.size(); i++){
      //cout << p << " " << q << endl;
      if(p >= (int)t.size()) ans += u[q++];
      else if(q >= (int)u.size()) ans += t[p++];
      else{
        if(t[p] < u[q]) ans += t[p++];
        else ans += u[q++];
      }
    }
    cout << ans << "\n";
  }
  flush(cout);

  return 0;
}