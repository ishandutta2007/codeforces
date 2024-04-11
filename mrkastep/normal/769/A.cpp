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

int n, a[25];

void solve() {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    printf("%d", a[n/2]);
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