#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <functional>
#include <cstring>
#include <cassert>
#include <numeric>

//#define FAST_ALLOCATOR_MEMORY 2e8
//#include "optimization.h"

using namespace std;

typedef long long ll;
typedef long double ld;
const ll md = (ll)1e9 + 7, inf = (ll)1e18;

const int N = 1e5 + 5;

int n, k;
int a[N];

void no() {
    puts("No");
    exit(0);
}

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\input.txt", "r", stdin);
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\output.txt", "w", stdout);
#endif

    scanf("%d %d", &n, &k);

    ll sum = 0;

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    if(sum % k) {
        no();
    }

    sum /= k;

    vector< int > ar;

    for(int i = 1;i <= n;i++) {
        int j = i;
        ll cur = 0;
        while(j <= n && cur < sum) {
            cur += a[j++];
        }
        j--;
        if(cur != sum) no();
        ar.push_back(j - i + 1);
        i = j;
    }

    puts("Yes");

    for(int x : ar) {
        printf("%d ", x);
    }

    printf("\n");

    return 0;
}