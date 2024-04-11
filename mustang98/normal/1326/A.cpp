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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if (n == 1) {
            printf("-1\n");
        } else {
            printf("2");
            for (int i = 0; i + 1 < n; ++i) {
                printf("3");
            }
            printf("\n");
        }
    }

    return 0;
}