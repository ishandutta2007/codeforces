#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10 ;
int a[nax], n;

void solve () {
    scanf("%d", &n);
    for (int i = 1 ;i <= n ;i ++) {
        scanf("%d", a + i);
    }
    a[n + 1] = 0;
    vector<int> keep;
    for (int i = 1 ; i <= n ; i ++) {
        if (a[i] == -1) continue;
        if (a[i - 1] == -1 || a[i + 1] == -1)
            keep.emplace_back(a[i]);
    }
    sort(keep.begin(), keep.end() );
    int tar = keep.empty() ? 0 : (keep.back() + keep[0])  / 2;
    for (int i = 1; i <= n ;i ++) {
        if (a[i] == -1) {
            a[i] = tar;
        }
    }
    int ans = 0;
    for (int i = 1; i < n ; i ++) {
        ans = max(ans, abs(a[i + 1] - a[i]));
    }
  /*  for (int i = 1 ;i <= n; i ++) {
        printf("%d ", a[i]);
    }*/
    printf("%d %d\n", ans, tar);
}

int main () {
    int T;
    for (cin >> T ; T -- ; solve() ) {


    }

}
/*
    Good Luck
        -Lucina
*/