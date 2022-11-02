#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

int n;
int a[MAXN], arr[MAXN], bit[MAXN];

int query(int i) {
    int sum = 0;
    for (i++; i>0; i-=i&-i) sum += bit[i];
    return sum;
}

void update(int i, int p) {
    for (i++; i<MAXN; i+=i&-i) bit[i] += p;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    for (int i=1; i<=n; i++) arr[i] = n+1;
    for (int i=0; i<n; i++) {
        int ind = query(a[i]) + 1;
        update(arr[ind], -1);
        update(a[i], 1);
        arr[ind] = a[i];
    }
    for (int i=n; i>=0; i--) {
        if (arr[i] != n+1) {
            printf("%d\n", i);
            return 0;
        }
    }
}