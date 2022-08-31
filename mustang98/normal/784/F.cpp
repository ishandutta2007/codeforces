#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 11, inf = 1000111222;

int m[max_n];
int m1[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }
    while(1.0 * clock() / CLOCKS_PER_SEC < 1.1) {};
    sort(m, m + n);
    //reverse(m, m + n);
    for (int i = 0; i < n; ++i) {
        cout << m[i] << ' ';
    }
    cout << endl;

    return 0;
}