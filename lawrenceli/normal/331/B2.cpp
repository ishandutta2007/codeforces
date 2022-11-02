#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 300010;

int n;
int pos[MAXN], bit[MAXN], arr[MAXN], perm[MAXN];
int q;

int query(int i) {
    int sum=0;
    for (i++; i>0; i-=i&-i) sum+=bit[i];
    return sum;
}

void update(int i, int p) {
    for (i++; i<MAXN; i+=i&-i) bit[i]+=p;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%d", &perm[i]);
        pos[perm[i]] = i;
    }
    for (int i=1; i<n; i++) {
        if (pos[i]>pos[i+1]) {
            arr[i] = 1;
            update(i, 1);
        }
    }
    scanf("%d", &q);
    for (int i=0; i<q; i++) {
        int p, x, y;
        scanf("%d %d %d", &p, &x, &y);
        if (p==1) {
            printf("%d\n", query(y-1)-query(x-1)+1);
        } else {
            swap(pos[perm[x]], pos[perm[y]]);
            swap(perm[x], perm[y]);
            x=perm[x]; y=perm[y]; swap(x, y);
            if (pos[x-1]<pos[x]) {
                update(x-1, -arr[x-1]);
                arr[x-1] = 0;
            }
            else {
                update(x-1, 1-arr[x-1]);
                arr[x-1] = 1;
            }
            if (pos[x]<pos[x+1]) {
                update(x, -arr[x]);
                arr[x] = 0;
            }
            else {
                update(x, 1-arr[x]);
                arr[x] = 1;
            }
            if (pos[y-1]<pos[y]) {
                update(y-1, -arr[y-1]);
                arr[y-1] = 0;
            }
            else {
                update(y-1, 1-arr[y-1]);
                arr[y-1] = 1;
            }
            if (pos[y]<pos[y+1]) {
                update(y, -arr[y]);
                arr[y] = 0;
            }
            else {
                update(y, 1-arr[y]);
                arr[y] = 1;
            }
        }
    }
}