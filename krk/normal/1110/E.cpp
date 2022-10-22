#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

map <int, int> A, B;
int a[Maxn], b[Maxn];

int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        A[a[i] - a[i - 1]]++;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        B[b[i] - b[i - 1]]++;
    }
    printf("%s\n", a[1] == b[1] && A == B? "Yes": "No");
    return 0;
}