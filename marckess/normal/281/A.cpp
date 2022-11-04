#include <iostream>
#include <string>

using namespace std;

int main(){
  string cad;

  cin >> cad;

  if(cad[0] < 'A' || cad[0] > 'Z')
    cad[0] = cad[0] - 'a' + 'A';
  cout << cad;


  return 0;
}