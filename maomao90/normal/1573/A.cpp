#include <bits/stdc++.h>
using namespace std;

#define REP(i, j, k) for (int i = j; i < k; i++)

int t;
int n;
char s[105];

int main() {
scanf("%d", &t);
while (t--) {
int ans = 0;
scanf("%d", &n);
scanf(" %s", s);
REP (i, 0, n) {
if (s[i] == '0') continue;
ans += s[i] - '0';
if (i != n - 1) ans++;
}
printf("%d\n", ans);
}
return 0;
}