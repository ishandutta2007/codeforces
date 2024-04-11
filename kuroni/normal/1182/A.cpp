#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << (n % 2 == 1 ? 0 : 1LL << (n / 2));
}