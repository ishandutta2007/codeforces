#include <iostream>
#include <algorithm>

using namespace std;

#define endl '\n'

const int maxn = 1000001;

long long cube[ maxn ];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    for (int i = 1; i < maxn; ++i)
        cube[i] = 1LL * i * i * i;

    while (t-->0){
        long long a, b;
        cin >> a >> b;
        long long n = a * b;
        long long g = __gcd(a, b); 
        g = g * g;

        if (binary_search(cube, cube+maxn, n) && (g % a == 0) && (g % b == 0))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}