#include <cstdio>
using namespace std;

int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i == j) printf("0");
            else if (i == n - 1) printf("%d", 2 * j % (n - 1) + 1);
            else if (j == n - 1) printf("%d", 2 * i % (n - 1) + 1);
            else printf("%d", (i + j) % (n - 1) + 1);
            printf("%c", j + 1 < n? ' ': '\n');
        }
    return 0;
}