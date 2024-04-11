#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

const int MAXN = 200100;
const int MAXA = 1000100;

int n, t, len, a[MAXN], freq[MAXA];

typedef long long ll;
ll num, ans[MAXN];

struct data {
    int l, r, id;
    data() {}
    data(int l, int r, int id) : l(l), r(r), id(id) {}
} arr[MAXN];

bool cmp(data d1, data d2) {
    return d1.l / len != d2.l / len ? d1.l / len < d2.l / len : d1.r < d2.r;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d", &n, &t); len = int(sqrt(n)) + 1;
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    for (int i=0; i<t; i++) {
        scanf("%d %d", &arr[i].l, &arr[i].r);
        arr[i].l --; arr[i].r --; arr[i].id = i;
    }
    sort(arr, arr + t, cmp);
    for (int i=0; i<t; ) {
        int l = arr[i].l, r = arr[i].r; num = 0;
        for (int j=0; j<MAXA; j++) freq[j] = 0;
        for (int j=l; j<=r; j++) {
            num += (ll(freq[a[j]]+1) * (freq[a[j]]+1) - ll(freq[a[j]]) * freq[a[j]]) * a[j];
            freq[a[j]] ++;
        }
        ans[arr[i].id] = num;
        int j;
        for (j = i+1; j < t && arr[i].l / len == arr[j].l / len; j++) {
            while (l != arr[j].l) {
                if (l > arr[j].l) {
                    l--;
                    num += (ll(freq[a[l]]+1)*(freq[a[l]]+1) - ll(freq[a[l]])*freq[a[l]]) * a[l];
                    freq[a[l]] ++;
                } else {
                    num += (ll(freq[a[l]]-1)*(freq[a[l]]-1) - ll(freq[a[l]])*freq[a[l]]) * a[l];
                    freq[a[l]] --;
                    l++;
                }
            }
            while (r < arr[j].r) {
                r++;
                num += (ll(freq[a[r]]+1)*(freq[a[r]]+1) - ll(freq[a[r]])*freq[a[r]]) * a[r];
                freq[a[r]] ++;
            }
            ans[arr[j].id] = num;
        }
        i = j;
    }
    for (int i=0; i<t; i++) printf("%I64d\n", ans[i]);
    return 0;
}