#include <bits/stdc++.h>

using namespace std;

int n, m;
bool good[105];

int main() {
cin >> n >> m;
for (int i = 0; i < n; i++) {
int x; cin >> x;
for (int j = 0; j < x; j++) {
int y; cin >> y;
good[y] = 1;
}
}

for (int i = 1; i <= m; i++)
if (!good[i]) {
cout << "NO\n";
return 0;
}
cout << "YES\n";
}