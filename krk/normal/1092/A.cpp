#include <bits/stdc++.h>
using namespace std;

int t;
int n, k;

int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            printf("%c", i % k + 'a');
        printf("\n");
    }
    return 0;
}