#include <iostream>
#include <vector>

using namespace std;

string names[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

int main() {
  int n; cin >> n; n--;
  while(n >= 5) {
    n -= 5;
    n /= 2;
  }
  cout << names[n] << endl;
}