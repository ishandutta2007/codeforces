#include <cstdio>

int n, a[105], ans[105], cnt, cur, k;

int main() {
scanf("%d", &n);
for (int i=0; i<n; i++) {
scanf("%d", &a[i]);
if (a[i] >= 0) cur++;
else if (a[i] < 0) {
if (k == 2) {
ans[cnt++] = cur;
cur = 1;
k = 1;
} else cur++, k++;
}
}
if (cur > 0) ans[cnt++] = cur;
printf("%d\n", cnt);
for (int i=0; i<cnt; i++) printf("%d ", ans[i]);
return 0;
}