#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    printf("%s\n", min(m, k) >= n? "Yes": "No");
    return 0;
}