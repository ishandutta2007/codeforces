#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1011, inf = 1000111222;

int m[max_n];


int main()
{
    //freopen("input.txt", "r", stdin);
    int T, n;
    cin >> T;
    while(T--) {
        cin >> n;
        int c[3] = {0};
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            c[a % 3]++;
        }
        int ans = c[0];
        int c1 = c[1];
        int c2 = c[2];
        ans = c[0] + min(c1, c2) + abs(c1 - c2) / 3;
        cout << ans << endl;
    }
}