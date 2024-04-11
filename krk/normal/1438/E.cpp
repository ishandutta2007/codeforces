#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
int a[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        int b = 0;
        while (1 << b <= a[i]) b++;
        // left
        if (i > 0) {
            int sum = a[i - 1];
            for (int j = i - 2; j >= 0 && sum < 1 << b; j--) {
                if (a[i] > a[j] && (a[i] ^ a[j]) == sum)
                    res++;
                sum += a[j];
            } 
        }
        // right
        if (i + 1 < n) {
            int sum = a[i + 1];
            for (int j = i + 2; j < n && sum < 1 << b; j++) {
                if (a[i] > a[j] && (a[i] ^ a[j]) == sum)
                    res++;
                sum += a[j];
            }
        }
    }
    printf("%d\n", res);
    return 0;
}