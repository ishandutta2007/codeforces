#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T --)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        long long x, y, z;
        x = b * c + a;
        y = b;
        z = c;
        cout << x << " " << y << " " << z << "\n";
    }

}