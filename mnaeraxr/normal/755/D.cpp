#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 1000010;

int64 bit[maxn];

void update(int idx){
    while (idx < maxn){
        bit[idx]++;
        idx += idx & -idx;
    }
}

int64 query(int idx){
    int64 ans = 0;
    while (idx){
        ans += bit[idx];
        idx -= idx & -idx;
    }
    return ans;
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    int64 answer = 1;

    k = min(k, n - k);

    for (int i = 0, p = 1; i < n; ++i){
        int np = p + k;
        if (np > n) np -= n;

        int64 total;

        if (np > p) total = query(np - 1) - query(p);
        else total = query(np - 1) + query(n) - query(p);

        answer += total + 1;

        printf("%lld ", answer);

        update(p);
        update(np);
        p = np;
    }

    putchar('\n');

    return 0;
}