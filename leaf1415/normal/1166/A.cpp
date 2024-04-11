#include <iostream>
#include <string>

using namespace std;

int n;
string s;
int cnt[26];

int main(void)
{
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> s;
    cnt[s[0]-'a']++;
  }

  int ans = 0;
  for(int i = 0; i < 26; i++){
    int x = cnt[i]/2, y = cnt[i]-x;
    ans += x*(x-1)/2, ans += y*(y-1)/2;
  }
  cout << ans << endl;

  return 0;
}