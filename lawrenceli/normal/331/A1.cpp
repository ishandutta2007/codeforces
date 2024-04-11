#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

#define repi(i, n) for (typeof(n.begin()) it = n.begin(), _##i = (n.end()); it != _##i; it++)

typedef long long ll;

const int MAXN = 300010;
const ll INF = 1e15;

int n, a[MAXN];
ll pre[MAXN];
map<int, int> fst, lst;
int best1, best2;
ll best = -INF;
int arr[MAXN], cnt;

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    for (int i=0; i<n; i++) {
        if (a[i]>0) pre[i+1]=pre[i]+a[i];
        else pre[i+1]=pre[i];
        if (!fst.count(a[i])) fst[a[i]] = i;
        lst[a[i]] = i;
    }
    repi(it, fst) {
        if (lst[it->first]==it->second) continue;
        ll res = a[it->second] + a[lst[it->first]] + pre[lst[it->first]] - pre[it->second+1];
        if (res>best) {
            best = res;
            best1 = it->second; best2 = lst[it->first];
        }
    }
    for (int i=0; i<best1; i++) arr[cnt++] = i;
    for (int i=best2+1; i<n; i++) arr[cnt++] = i;
    for (int i=best1+1; i<best2; i++) {
        if (a[i]<0) arr[cnt++] = i;
    }
    printf("%I64d %d\n", best, cnt);
    for (int i=0; i<cnt; i++) printf("%d ", arr[i]+1);
}