#include <iostream>
#include <string>

using namespace std;

int n;
string s;
int m[15];

int main(void)
{
  cin >> n;
  cin >> s;
  for(int i = 1; i <= 9; i++) cin >> m[i];

  bool flag = false;
  for(int i = 0; i < s.size(); i++){
    int x = s[i]-'0';
    if(flag){
      if(m[x] >= x) s[i] = m[x]+'0';
      else break;
    }
    else{
      if(m[x] > x){
        s[i] = m[x] + '0';
        flag = true;
      }
    }
  }
cout << s << endl;
  return 0;
}