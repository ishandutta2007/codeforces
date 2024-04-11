#define NDEBUG
#include <iostream>
#include <string>
using namespace std;


int main() {
  ios_base::sync_with_stdio(0);

  int len;
  cin >> len;
  string str;
  cin >> str;

  for (int d=1; d<=len; ++d) {
    for (int start=0; start<len; ++start) {
      int i = 0;
      for (i = 0; i < 5 && start + i*d < len && str[start + i*d] == '*'; ++i) ;
      if (i == 5) {
        cout << "yes\n";
        return 0;
      }
    }
  }

  cout << "no\n";
}