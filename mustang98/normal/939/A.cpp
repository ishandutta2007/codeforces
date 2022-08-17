#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 5001, inf = 1000111222;

int f[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
        --f[i];
    }
    for (int i = 0; i < n; ++i) {
        int A = i;
        int B = f[i];
        int C = f[B];
        if (C == A) continue;
        if (f[C] == A) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}