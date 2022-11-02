#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAX_N = 100000;

int N, m[MAX_N];

signed main()
{
    int sum = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> m[i];
        sum += m[i];
    }
    int ans = 0;
    sort(m, m + N);
    for (int i = 0; i < N; i++)
    {
        int target = sum/N + 1;
        if (i < (N - sum % N)) target--;
        ans += abs(m[i] - target);
    }
    printf("%I64d\n", ans/2);
    return 0;
}