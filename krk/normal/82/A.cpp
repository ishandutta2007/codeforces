#include <iostream>
#include <string>
using namespace std;

string names[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
long long n;

int main()
{
    long long nw = 0, drinks = 1;
    cin >> n; n--;
    while (nw <= n-5*drinks) {
          nw += 5*drinks;
          drinks *= 2;
    }
    int st = 0;
    while (nw <= n - drinks) {
          st++;
          nw += drinks;
    }
    cout << names[st] << endl;
    return 0;
}