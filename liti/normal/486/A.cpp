//In the name of Allah
#include <iostream>
using namespace std;

int main() { 
 long long n;
 cin >> n;
 cout << (n%2?-n + n/2: n/2) << endl;
}