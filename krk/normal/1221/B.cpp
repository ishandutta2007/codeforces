#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%c", (i + j) % 2? 'B': 'W');
        printf("\n");
    }
    return 0;
}