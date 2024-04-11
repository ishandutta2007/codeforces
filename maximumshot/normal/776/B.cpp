#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 100005;

bool prime[N];
vec< int > d[N];
int color[N];
int arr[N];
int sz;

int main() {

    for(int i = 0;i < N;i++) prime[i] = 1;
    prime[0] = prime[1] = 0;

    for(int i = 2;i * i < N;i++) {
        if(!prime[i]) continue;
        for(int j = i * i;j < N;j += i) prime[j] = 0;
    }

    for(int i = 2;i < N;i++) {
        if(!prime[i]) continue;
        for(int j = 2 * i;j < N;j += i) d[j].push_back(i);
    }

    int n;

    scanf("%d", &n);

    for(int i = 2;i <= n + 1;i++) {
        if(prime[i]) continue;
        sz = 0;
        for(int x : d[i]) arr[sz++] = color[x];
        sort(arr, arr + sz);
        sz = unique(arr, arr + sz) - arr;
        if(arr[0] > 0) color[i] = 0;
        else {
            int ok = 0;
            for(int j = 0;j + 1 < sz;j++) {
                if(arr[j] + 1 < arr[j + 1]) {
                    color[i] = arr[j] + 1;
                    ok = 1;
                    break;
                }
            }
            if(!ok) color[i] = arr[sz - 1] + 1;
        }
    }

    int k = 0;

    for(int i = 2;i <= n + 1;i++) {
        k = max(k, color[i] + 1);
    }

    printf("%d\n", k);

    for(int i = 2;i <= n + 1;i++) {
        printf("%d ", color[i] + 1);
    }

    printf("\n");

    return 0;
}