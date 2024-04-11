#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int a[105];
bool exists[105];
vector <int> ans;

int main() {
scanf("%d", &t);
while (t--) {
ans.clear();
scanf("%d", &n);
memset(exists, 0, sizeof exists);
for (int i = 0; i < n * 2; i++) {
scanf("%d", &a[i]);
if (!exists[a[i]]) ans.push_back(a[i]);
exists[a[i]] = true;
}
for (int i : ans) printf("%d ", i);
printf("\n");
}
return 0;
}