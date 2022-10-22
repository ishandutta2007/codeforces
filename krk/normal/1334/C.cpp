#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;

int T;
int n;
ll A[Maxn], B[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%I64d %I64d", &A[i], &B[i]);
        vector <ll> los;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            int j = (i - 1 + n) % n;
            sum += max(0ll, A[i] - B[j]);
            los.push_back(A[i] - max(0ll, A[i] - B[j]));
        }
        sort(los.begin(), los.end());
        sum += los[0];
        printf("%I64d\n", sum);
    }
    return 0;
}