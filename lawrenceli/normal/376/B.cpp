#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

int n, m, mat[105][105];

int main() {
ios :: sync_with_stdio(0);

cin >> n >> m;
for (int i=0; i<m; i++) {
int a, b, c;
cin >> a >> b >> c;
a--; b--;
mat[a][b] = c;
}

for (int l=0; l<n; l++)
for (int i=0; i<n; i++)
for (int j=0; j<n; j++)
for (int k=0; k<n; k++) {
int x = min(mat[i][j], mat[j][k]);
mat[i][j] -= x;
mat[j][k] -= x;
mat[i][k] += x;
}

int ans = 0;
for (int i=0; i<n; i++)
for (int j=0; j<n; j++)
ans += mat[i][j];

cout << ans << '\n';
return 0;
}