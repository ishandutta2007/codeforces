#include <iostream>

using namespace std;

int K;
string c = "aiueo";

int main(void)
{
  cin >> K;
  for(int i = 5; i <= K; i++){
    if(K%i == 0 && K/i >= 5){
      int x = K/i;
      string ans;
      for(int j = 0; j < i; j++){
        for(int k = 0; k < x; k++){
          ans += c[(j+k)%5];
          /*if(j>=5||k>=5) ans+="a";
          else{
            ans += c[(j+k)%5];
          }*/
        }
      }
      cout << ans << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}