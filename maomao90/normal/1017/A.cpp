#include <bits/stdc++.h>
using namespace std;

int n;
int sum[1005];
int me;

int main() {
scanf("%d", &n);
for (int i = 0; i < n; i++) {
int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
sum[i] = a + b + c + d;
}
me = sum[0];
sort(sum, sum + n, greater<int>());
for (int i = 0; i < n; i++) {
if (me >= sum[i]) {
printf("%d\n", i + 1);
return 0;
}
}
}