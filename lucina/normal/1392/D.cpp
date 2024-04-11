#include<bits/stdc++.h>
using namespace std;
const int nax = 4e5 + 10;
int n;
char s[nax];
int f(int x) {
    return (x + 2) / 3;
}

void solve() {
    cin >> n >> s + 1;
    if (*max_element(s + 1, s + 1 + n) == 'L' || *min_element(s + 1, s + 1 + n) == 'R') {
        cout << f(n) << '\n';
        return ;
    }

    int st = 1;
    while (s[st] == s[n]) ++ st;

    for (int i = n + 1 ; i <= n + n ; ++ i) {
        s[i] = s[i - n];
    }

    int new_n = n + st - 1;

    int ans = 0;
  //  printf("new_n %d st %d\n", new_n, st);

    for (int i = st; i <= new_n ; ++ i) {
        int j = i;
        while (j <= new_n && s[j] == s[i]) ++ j;
        int len = j - i;
        ans += len / 3;
    //    printf("%d ", len);
        i = j - 1;
    }
   // puts("");
    cout << ans << '\n';
}

int main () {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    cin >> T;

    for (; T -- ;) {
        solve();
    }

}
/**
    Try virtual.
*/