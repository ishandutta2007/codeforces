#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> piii;

const int MAXN = 100010;

int n, p, k;
piii a[MAXN];
int num[MAXN], cnt;

bool cmp1(piii p1, piii p2) {
    return p1.first.second!=p2.first.second ? p1.first.second>p2.first.second : p1.first.first<p2.first.first;
}

bool cmp2(piii p1, piii p2) {
    return p1.first.first!=p2.first.first ? p1.first.first>p2.first.first : p1.first.second>p2.first.second;
}

bool cmp3(piii p1, piii p2) {
    return p1.first.second>p2.first.second;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d %d", &n, &p, &k);
    for (int i=0; i<n; i++) scanf("%d %d", &a[i].first.first, &a[i].first.second);
    for (int i=0; i<n; i++) a[i].second=i;
    sort(a, a+n, cmp1);
    sort(a, a+n-p+k, cmp2);
    //for (int i=0; i<n; i++) cout << a[i].first.first << ' ' << a[i].first.second << ' ' << a[i].second+1 << endl;
    int best1=1e9, best2;
    for (int i=0; i<k; i++) {
        num[cnt++]=a[i].second;
        if (best1>a[i].first.second) {
            best1=a[i].first.second;
            best2=a[i].first.first;
        }
        else if (best1==a[i].first.second) best2=max(best2, a[i].first.first);
    }
    sort(a+k, a+n, cmp3);
    for (int i=k; i<n && cnt<n; i++) {
        if (a[i].first.second<best1 || a[i].first.second==best1 && a[i].first.first>=best2) num[cnt++]=a[i].second;
    }
    for (int i=0; i<p; i++) {
        printf("%d", num[i]+1);
        if (i<p-1) printf(" ");
        else printf("\n");
    }
}