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

bool g(int a) {
    int s = 0;
    while(a) {
        s += a % 10;
        a /= 10;
    }
    return s % 4 == 0;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int a;
    cin >> a;
    for (int i = a;;++i) {
        if (g(i)) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}