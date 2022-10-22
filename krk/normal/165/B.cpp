#include <cstdio>
using namespace std;

int n, k;

bool Good(int v)
{
    int sum = 0;
    while (v && sum < n) {
        sum += v;
        v /= k;
    }
    return sum >= n;
}

int main()
{
    scanf("%d %d", &n, &k);
    int l = 1, r = n;
    while (l < r) {
        int mid = l + r >> 1;
        if (Good(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}