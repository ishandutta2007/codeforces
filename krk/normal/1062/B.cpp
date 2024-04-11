#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> seq;
int res1 = 1, res2;

int main()
{
    scanf("%d", &n);
    int mx = 0;
    for (int i = 2; i <= n; i++) if (n % i == 0) {
        int cnt = 0;
        res1 *= i;
        while (n % i == 0) { cnt++; n /= i; }
        seq.push_back(cnt);
        while ((1 << mx) < cnt) mx++;
    }
    res2 = mx;
    for (int i = 0; i < seq.size(); i++)
        if (seq[i] < (1 << mx)) { res2++; break; }
    printf("%d %d\n", res1, res2);
    return 0;
}