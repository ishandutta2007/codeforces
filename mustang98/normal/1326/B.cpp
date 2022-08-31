#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

ll m[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i =0 ; i < n; ++i) {
        int a;
        scanf("%d", &a);
        m[i] = a;
    }
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        int cur = m[i] + mx;
        printf("%d ", cur);
        mx = max(mx, cur);
    }

    return 0;
}