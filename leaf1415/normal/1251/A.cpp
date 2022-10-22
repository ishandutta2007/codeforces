#include <iostream>
#include <string>

using namespace std;

int T;
string s;
bool used[26];

int main(void)
{
  cin >> T;
  for(int t = 0; t < T; t++){
    cin >> s;
    s += "#";
    for(int i = 0; i < 26; i++) used[i] =false;
    int cnt = 1; char pre;
    for(int i = 0; i < s.size(); i++){
      if(i > 0){
        if(s[i] == pre) cnt++;
        else{
          if(cnt % 2) used[pre-'a'] = true;
          cnt = 1;
        }
      }
      pre = s[i];
    }
    string ans;
    for(int i = 0; i < 26; i++) if(used[i]) ans += (char)(i+'a');
    cout << ans << "\n";
  }
  flush(cout);

  return 0;
}