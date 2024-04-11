#include <bits/stdc++.h>
using namespace std;

int d, n;
int ans;

int main() {
scanf("%d%d", &d, &n);
for (int i = 0; i < n - 1; i++) {
int a; scanf("%d", &a);
ans += d - a;
}
printf("%d\n", ans);
return 0;
}