#include <iostream>
using namespace std;

int n, A, B, C;

int main()
{
    int a, b, c;
    cin >> n;
    while (n--) {
          cin >> a >> b >> c;
          A += a; B += b; C += c;
    }
    if (A == 0 && B == 0 && C == 0) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}