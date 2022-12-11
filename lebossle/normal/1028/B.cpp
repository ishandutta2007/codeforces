#include <iostream>
#include <vector>

using namespace std;

int main() {
  cout << string(200, '9') << endl;
  cout << string(200, '9') << string(199, '0') << 1 << endl;
}