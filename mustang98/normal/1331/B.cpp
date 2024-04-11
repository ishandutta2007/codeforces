#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int a;
    cin >> a;
    for (int i = 2; i < a; ++i) {
        if (a % i == 0) {
            cout << i << a / i << endl;
            return 0;
        }
    }

    return 0;
}