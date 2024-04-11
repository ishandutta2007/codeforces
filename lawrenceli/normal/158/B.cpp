#include <cstdio>
#include <algorithm>
using namespace std;

int freq[5];

int main() {
int n; scanf("%d", &n);
for (int i=0; i<n; i++) {
int x; scanf("%d", &x);
freq[x] ++;
}

int ans = 0;
ans += freq[4];
ans += freq[2] >> 1;
freq[2] &= 1;
int sub = 2*freq[2] + freq[3];
ans += freq[2] + freq[3];
if (freq[1] - sub > 0) ans += (freq[1] - sub - 1) / 4 + 1;
printf("%d\n", ans);
}