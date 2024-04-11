#include <iostream>
#include <ios>

using namespace std;

int n, m, k;

int main() {
ios :: sync_with_stdio(false);

cin >> n >> m >> k;
cout << m*(m-1)/2 << '\n';
if (k == 0) {
for (int i=1; i<=m; i++)
    for (int j=1; j<=m-i; j++)
        cout << j << ' ' << j+1 << '\n';
} else {
for (int i=m; i>=1; i--)
    for (int j=m; j>m-i+1; j--)
        cout << j << ' ' << j-1 << '\n';
}
}