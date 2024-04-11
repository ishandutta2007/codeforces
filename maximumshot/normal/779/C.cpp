#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 2e5 + 5;

int n, k;
int a[N];
int b[N];

bool cmp(int i, int j) {
    return a[i] - b[i] < a[j] - b[j];
}

int main() {

    scanf("%d %d", &n, &k);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 1;i <= n;i++) {
        scanf("%d", &b[i]);
    }

    vec< int > arr;
    for(int i = 1;i <= n;i++) arr.push_back(i);

    sort(ALL(arr), cmp);

    int s1 = 0;
    int s2 = 0;
    int res = INT_MAX;

    for(int x : arr) s2 += b[x];

    for(int i = 0;i <= (int)arr.size();i++) {
        if(i >= k) {
            res = min(res, s1 + s2);
        }
        if(i < (int)arr.size()) {
            s1 += a[arr[i]];
            s2 -= b[arr[i]];
        }
    }

    printf("%d\n", res);

    return 0;
}