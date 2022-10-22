#include <bits/stdc++.h>
using namespace std;

int t;
int n, m;

int main() {
scanf("%d", &t);
while (t--) {
scanf("%d%d", &n, &m);
if (n > m && n % m == 0) printf("Yes\n");
else printf("No\n");
}
return 0;
}