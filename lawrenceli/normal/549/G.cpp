#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200100;

int n, a[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        a[i] += i;
    }

    sort(a, a+n);
    for (int i=0; i<n-1; i++)
        if (a[i] == a[i+1]) {
            cout << ":(";
            return 0;
        }

    for (int i=0; i<n; i++)
        cout << a[i]-i << ' ';
}