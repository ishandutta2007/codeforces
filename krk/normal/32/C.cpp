#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
    ll n, m, s;
    cin >> n >> m >> s;
    ll resn = (n - 1) / s + 1, resm = (m - 1) / s + 1;
    cout << (ll) ((n - 1) % s + 1) * ((m - 1) % s + 1) * resn * resm << endl;
    return 0;
}