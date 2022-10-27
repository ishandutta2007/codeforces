#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int a[nax];

void solve () {
    int n;
    scanf("%d", &n);
    vector <int> ans;
    for (int i = 1 ; i <= n; ++ i) {
        scanf("%d", a + i);
    }
    ans.push_back(a[1]);


    for (int i = 2 ; i < n ; ++ i) {
        if ((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1])) {
            ans.push_back(a[i]);
        }
    }
    ans.push_back(a[n]);
    printf("%d\n", (int)ans.size());
    for (int k : ans)
        printf("%d ", k);
    printf("\n");
}

int main () {
    int T;
    for (cin >> T ; T -- ; ) {
        solve();
    }
}