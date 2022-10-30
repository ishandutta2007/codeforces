#pragma warning (disable: 4996)
#include <iostream> 
#include <stdio.h> 
#include <cstdio> 
#include <algorithm> 
#include <vector> 
#include <map> 
#include <set> 
#include <string> 
#include <cstring> 
#include <valarray> 
#include <tuple> 
#include <complex> 
#include <bitset> 
#include <assert.h> 
#include <unordered_map> 

#define pb push_back 
#define mp make_pair 

typedef long long ll;

using namespace std;

int n, a[20005];

void solve() {
    int i, j,k, ans = -1e9;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 1; i <= n; i++) {
        if (n%i == 0 && n / i >= 3) {
            for (k = 0; k < i; k++) {
                int sum = 0;
                for (j = k; j < n; j += i) {
                    sum += a[j];
                }
                ans = max(ans, sum);
            }
        }
    }
    printf("%d", ans);
}

int main() {
#ifdef _DEBUG 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif 
    scanf("%d", &n);
    solve();
    return 0;
}