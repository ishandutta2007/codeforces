#include <bits/stdc++.h>
using namespace std;

int n, a[100005], f[100005], m[100005], c;

int main() {
cin >> n;
for (int i=0; i<n; i++) {
cin >> a[i];
f[a[i]]++;
}
for (int i=1; i<=n; i++)
if (!f[i]) m[c++] = i;

for (int i=0; i<n; i++)
if (f[a[i]] > 1 || a[i] > n) {
f[a[i]]--;
a[i] = m[--c];
}

for (int i=0; i<n; i++) cout << a[i] << ' ';
}