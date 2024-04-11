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

int m[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i =0 ; i < n; ++i) {
            scanf("%d", m + i);
        }
        bool f = 0;
        for (int i = 0; i + 1 < n; ++i) {
            if (abs(m[i] - m[i + 1]) >= 2) {
                printf("YES\n");
                printf("%d %d\n", i + 1, i + 2);
                f = 1;
                break;
            }
        }
        if (!f) {
            printf("NO\n");
        }
    }

    return 0;
}