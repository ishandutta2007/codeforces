#pragma warning (disable:4996)
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

int n, k, a[205];

void solve() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > 0 && a[i]>=a[k-1]) {
            ans++;
        }
    }
    printf("%d", ans);
}


int main() {
#ifdef _DEBUG 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    solve();
    return 0;
}