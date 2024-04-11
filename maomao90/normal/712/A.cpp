#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000005];
long long b[1000005];

int main() {
cin >> n;
for (int i = 0; i < n; i++) {
cin >> a[i];
}
long long res = 0;
for (int i = n - 1; i >= 0; i--) {
b[i] = a[i] + res;
res = b[i] - res;
}
for (int i = 0; i < n; i++) {
cout << b[i] << '\n';
}
}