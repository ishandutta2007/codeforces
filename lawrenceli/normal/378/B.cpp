#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

const int MAXN = 100100;

int n, a[MAXN], b[MAXN], ans[2], num, p1, p2;

void advance() {
    if (p1 == n-1) p2++;
    else if (p2 == n-1) p1++;
    else if (a[p1+1] < b[p2+1]) p1++;
    else p2++;
}

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }

    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i] >> b[i];
    p1 = -1, p2 = -1;
    for (int i=0; i<n; i++) advance();
    num = n;
    ans[0] = p1, ans[1] = p2;

    int k;
    for (k=0; 2*k <= n; k++);

    ans[0] = max(ans[0], k-2); ans[1] = max(ans[1], k-2);

    for (int i=0; i<=ans[0]; i++) cout << 1;
    for (int i=ans[0]+1; i<n; i++) cout << 0;
    cout << endl;
    for (int i=0; i<=ans[1]; i++) cout << 1;
    for (int i=ans[1]+1; i<n; i++) cout << 0;
    cout << endl;

    return 0;
}