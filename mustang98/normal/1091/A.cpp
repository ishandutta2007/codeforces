#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = -1, inf = 1000111222;

int main()
{
    //freopen("input.txt", "r", stdin);
    int a, b, c;
    cin >> a >> b >> c;
    int maxa = 1;
    for (int i = 1; i <= a; ++i) {
        if (i + 1 <= b && i + 2 <= c) {
            maxa = i;
        }
    }
    cout << maxa * 3 + 3 << endl;

    return 0;
}