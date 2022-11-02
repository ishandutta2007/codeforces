#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
const int M = 1000000007;

int T, n;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        ++n;
        printf("%d\n", n / 10);
    }
    return 0;
}