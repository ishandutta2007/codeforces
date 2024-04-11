#include <iostream>
using namespace std;

typedef long long ll;

ll n, x, y;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n >> x >> y;
    ll lft = y - (n - 1LL);
    if (lft <= 0 || n - 1LL + lft * lft < x) cout << "-1\n";
    else {
         for (int i = 0; i < n - 1; i++)
            cout << "1\n";
         cout << lft << endl;
    }
    return 0;
}