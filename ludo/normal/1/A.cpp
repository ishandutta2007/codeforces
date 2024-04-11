#include <iostream>

using namespace std;

typedef unsigned long long ll;

int main()
{
    ll n, m, a;
    cin >> n >> m >> a;
    cout << (n / a + (n % a != 0)) * (m / a + (m % a != 0)) << endl;
    return 0;
}