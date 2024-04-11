#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    unsigned long long n, m, a;
    cin >> n >> m >> a;
    cout << ((n-1)/a+1)*((m-1)/a+1) << endl;
}