#include <iostream>
#include <string>

using namespace std;

string s;

int main(void)
{
  cin >> s;
  int n = s.size();

  cout << 0 << " ";
  if(n == 1){
    cout << endl;
    return 0;
  }
  char back = s[1];
  for(int i = 2; i < n; i++){
    if(back != s[i]) cout << 1 << " ";
    else cout << 0 << " ";
    back = s[i];
  }
  if(back == 'a') cout << 1 << endl;
  else cout << 0 << endl;

  return 0;
}