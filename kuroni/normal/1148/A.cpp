#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    cout << (c + min(a, b)) * 2 + (a != b);
}