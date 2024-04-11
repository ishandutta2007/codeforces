#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

int m[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int c1 = 0, c0 = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a % 2 ==0) {
            ++c0;
        } else {
            ++c1;
        }
    }
    cout << min(c1, c0);


    return 0;
}