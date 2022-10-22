#include <iostream>
#include <string>

using namespace std;

int Q;

int main(void)
{
  cin >> Q;
  int n, k;
  for(int q = 0; q < Q; q++){
    cin >> n >> k;

    for(int i = 0; i < k; i++){
      for(int j = 0; j < n/k; j++) cout << (char)(i+'a');
    }
    for(int i = 0; i < n%k; i++) cout << 'a';
    cout << endl;
  }
  return 0;
}