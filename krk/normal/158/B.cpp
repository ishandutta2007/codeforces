#include <cstdio>
#include <algorithm>
using namespace std;

int n, s[5];
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int num; scanf("%d", &num);
        s[num]++;
    }
    res += s[4]; s[4] = 0;
    int p = min(s[1], s[3]); res += p; s[1] -= p; s[3] -= p;
    res += s[3]; s[3] = 0;
    p = s[2] / 2; res += p; s[2] -= 2 * p;
    if (s[2]) { res += s[2]; s[2] = 0; s[1] = max(0, s[1] - 2); }
    res += s[1] / 4 + (s[1] % 4 > 0);
    printf("%d\n", res);
    return 0;
}